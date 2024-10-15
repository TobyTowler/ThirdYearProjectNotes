import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';

import 'editor.dart';
import 'main.dart';

class Region extends StatefulWidget {
  Region({super.key, required this.latlong, required this.parentSetState});

  /// Boundary points for the satellite image
  LatLngBounds latlong;

  /// Callback function to refresh state of parent
  final void Function() parentSetState;

  @override
  _RegionState createState() => _RegionState();
}

/// Extends the [FileSystemEntity] to add the file's name
extension FileSystemEntityName on FileSystemEntity {
  String get name {
    return path.split("/").last;
  }
}

/// Extends the [File] to add the file's extension
extension FileExtention on File {
  String get ext {
    return path.split(".").last;
  }
}

/// Extends the [File] to add the file's name
extension FileName on File {
  String get name {
    return path.split("/").last.split(".").first;
  }
}

class _RegionState extends State<Region> {
  /// Gives the number of saved region folders
  int regionCount() {
    final Directory dir = Directory("${Options.directory.path}/regions");
    final List<FileSystemEntity> entities =
        dir.listSync(recursive: false).toList(growable: false);

    final Iterable<Directory> regions = entities.whereType<Directory>();

    return regions.toList(growable: false).length;
  }

  /// Adds a new region folder with a sequential name
  int addRegion(String filename) {
    int count = regionCount();
    Directory('${Options.directory.path}/regions/${count.toString()}')
        .createSync(recursive: false);
    File('${Options.directory.path}/regions/${count.toString()}/$filename.txt').createSync();

    return count;
  }

  /// Renames all region folders above the deleted folder to be one less
  /// thus making them in sequential order from 0
  void renameRegions(int deleted) {
    final Directory dir = Directory("${Options.directory.path}/regions");
    final List<FileSystemEntity> entities =
        dir.listSync(recursive: false).toList(growable: false);

    final Iterable<Directory> regions = entities.whereType<Directory>();
    for (var element in regions) {
      if (int.tryParse(element.name) != null) {
        int current = int.parse(element.name);
        if (current > deleted) {
          element
              .renameSync("${Options.directory.path}/regions/${(current - 1)}");
        }
      }
    }
  }

  bool nameAlertReturn = false;
  String regionName = "";
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [
        // Image of mower on top of region - would be the robot's actual position
        Expanded(
            flex: 1,
            child: Stack(children: [
              Image.memory(
                Options.savedImage,
              ),
              Positioned(
                top: 100,
                left: 100,
                width: 50,
                height: 50,
                child: Image.asset("assets/images/lawn_mower.png"),
              ),
            ])),
        Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                // Renaming the selected region
                ElevatedButton(
                    onPressed: () {
                      showDialog(
                        barrierDismissible: false,
                        context: context,
                        builder: (BuildContext context) => AlertDialog(
                          title: const Text("Enter a name for the new region"),
                          content: Form(
                            key: _formKey,
                            child: TextFormField(
                              onSaved: (String? value) {
                                regionName = value!;
                              },
                              validator: (value) {
                                if (value == null || value.isEmpty) {
                                  return "Please enter a name";
                                }
                                return null;
                              },
                              decoration: const InputDecoration(
                                  border: OutlineInputBorder(),
                                  labelText: "Region Name",
                                  hintText: "Front Lawn"),
                            ),
                          ),
                          actions: [
                            ElevatedButton(
                              child: const Text("Cancel"),
                              onPressed: () {
                                nameAlertReturn = false;
                                Navigator.of(context).pop();
                              },
                            ),
                            ElevatedButton(
                              child: const Text("Confirm"),
                              onPressed: () {
                                if (_formKey.currentState!.validate()) {
                                  _formKey.currentState?.save();
                                  nameAlertReturn = true;
                                  if (nameAlertReturn) {
                                    Options.currentRegion = addRegion(regionName);
                                    Options.mapSelected = true;
                                    Options.mapSaved = false;
                                    Options.savedImage = Uint8List(0);
                                    widget.parentSetState();
                                  }
                                  Navigator.of(context).pop();
                                }
                              },
                            ),
                          ],
                          elevation: 24,
                        ),
                      );
                    },
                    child: const Text("Add")),
                Container(
                    margin: const EdgeInsets.only(left: 10, right: 10),
                    child: ElevatedButton(
                        onPressed: () {
                          Navigator.push(
                              context,
                              MaterialPageRoute(
                                  builder: (context) => const Editor()));
                        },
                        child: const Text("Edit"))),
                // Delete currently selected region
                ElevatedButton(
                    onPressed: () async {
                      await Directory(
                              '${Options.directory.path}/regions/${Options.currentRegion.toString()}')
                          .delete(recursive: true)
                          .catchError((onError) {
                        if (kDebugMode) {
                          print(onError);
                        }
                      });
                      renameRegions(Options.currentRegion);

                      if (regionCount() == 0) {
                        Options.mapSelected = false;
                        Options.mapSaved = false;
                        Options.fileSaved = false;
                        Options.savedImage = Uint8List(0);
                      } else {
                        Options.currentRegion = 0;
                        Options.mapSelected = true;
                        Options.mapSaved = true;
                        Options.fileSaved = true;
                        Options.savedImage = File(
                                '${Options.directory.path}/regions/${Options.currentRegion.toString()}/image.png')
                            .readAsBytesSync();
                      }

                      widget.parentSetState();
                    },
                    child: const Text("Delete")),
                Container(
                  margin: const EdgeInsets.only(left: 10, right: 10),
                  child: ElevatedButton(
                      onPressed: () {
                        setState(() {
                          Options.renameRegion(Options.currentRegion, context, widget.parentSetState);
                        });
                      },
                      child: const Text("Rename")),
                ),
              ],
            ),
          ],
        )
      ],
    );
  }
}
