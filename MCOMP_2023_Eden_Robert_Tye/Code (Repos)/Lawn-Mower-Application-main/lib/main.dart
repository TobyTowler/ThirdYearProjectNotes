import 'dart:convert';
import 'dart:core';
import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:lawnmower/camera_ortho.dart';
import 'package:lawnmower/mower.dart';
import 'package:path_provider/path_provider.dart';
import 'package:permission_handler/permission_handler.dart'
    as permission_handler;
import 'package:lawnmower/capture_map.dart';
import 'package:lawnmower/confirmation_screen.dart';
import 'package:lawnmower/login_screen.dart';
import 'package:lawnmower/region.dart';

import 'editor.dart';


/*
  TODO:
        * Set up connection to server
        * Comments
 */

void main() => runApp(const MowerApp());

class MowerApp extends StatelessWidget {
  const MowerApp({super.key});

  static const String _title = 'Home';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: _title,
      home: const MainStatefulWidget(),
      initialRoute: '/home',
      routes: {
        '/editor': (context) => const Editor(),
        '/mower': (context) => const Mower(),
        '/home': (context) => const MainStatefulWidget(),
      },
    );
  }
}

class MainStatefulWidget extends StatefulWidget {
  const MainStatefulWidget({super.key});

  @override
  State<MainStatefulWidget> createState() => _MainStatefulWidgetState();
}

class _MainStatefulWidgetState extends State<MainStatefulWidget> {

  // Check for saved files on the user's device - images and json of regions
  void _checkFile() async {
    Options.directory = await getApplicationDocumentsDirectory();
    Options.storagePermissionStatus =
        await permission_handler.Permission.storage.status;

    if (Options.storagePermissionStatus !=
        permission_handler.PermissionStatus.granted) {
      permission_handler.PermissionStatus permissionStatus =
          await permission_handler.Permission.storage.request();
      setState(() {
        Options.storagePermissionStatus = permissionStatus;
      });
    }
    if (!Directory('${Options.directory.path}/regions/').existsSync()) {
      Directory('${Options.directory.path}/regions/')
          .createSync(recursive: true);
    }
    Options.numberOfRegions = Directory('${Options.directory.path}/regions/')
        .listSync(recursive: false)
        .length;
    bool exists = Options.numberOfRegions <= 0 ? false : true;
    bool fileExists = File(
            '${Options.directory.path}/regions/${Options.currentRegion.toString()}/image.png')
        .existsSync();

    setState(() {
      Options.fileSaved = exists;
    });
    // If the directory and files exists then set selected and saved options
    // this does not check for json files as it is assumed present as they
    // are saved together
    if (exists == true && fileExists == true) {
      Options.savedImage = await File(
              '${Options.directory.path}/regions/${Options.currentRegion.toString()}/image.png')
          .readAsBytes();
      setState(() {
        Options.fileSaved = true;
        Options.mapSaved = true;
        Options.mapSelected = true;
      });
    }
  }

  // Get GPS permissions from the user - Google Maps won't work otherwise
  void _gpsPermissions() async {
    Options.locationPermissionStatus =
        await permission_handler.Permission.location.status;

    if (Options.locationPermissionStatus !=
        permission_handler.PermissionStatus.granted) {
      permission_handler.PermissionStatus permissionStatus =
          await permission_handler.Permission.location.request();
      setState(() {
        Options.locationPermissionStatus = permissionStatus;
      });
    }
  }

  @override
  void initState() {
    super.initState();
    setState(() {
      _checkFile();
      _gpsPermissions();
    });
  }

  int _selectedIndex = 0;

  void _onItemTapped(int index) {
    if(!Options.loggedIn) {
      return;
    }
    setState(() {
      _selectedIndex = index;
    });
    if (index == 1) {
      Navigator.popAndPushNamed(context, '/mower');
    }
  }

  void _onMapSelected() {
    setState(() {
      Options.mapSelected = true;
    });
  }
  /// Updates the current bounds selected - required for editing a region
  void updateLatLongBounds(LatLngBounds latLngBounds) {
    Options.latlong = latLngBounds;
  }

  final ButtonStyle raisedButtonStyle = ElevatedButton.styleFrom(
    foregroundColor: Colors.black87,
    backgroundColor: Colors.grey[300],
    minimumSize: const Size(88, 36),
    padding: const EdgeInsets.symmetric(horizontal: 16),
    shape: const RoundedRectangleBorder(
      borderRadius: BorderRadius.all(Radius.circular(2)),
    ),
  );

  // Drop down items for selecting saved regions
  List<DropdownMenuItem<int>> get dropdownItems {
    final Directory dir = Directory("${Options.directory.path}/regions");
    final List<FileSystemEntity> entities =
        dir.listSync(recursive: false).toList(growable: false);

    final Iterable<Directory> regions = entities.whereType<Directory>();

    int count = regions.toList(growable: false).length;

    List<DropdownMenuItem<int>> menuItems = [
      for (int i = 0; i < count; i++)
        DropdownMenuItem(value: i, child: Text(Options.getRegionName(i)))
    ];
    return menuItems;
  }

  void callBackSetState() {
    setState(() {});
  }

  Widget viewSelector() {
    // If user is logged in
    if (Options.loggedIn == false) {
      return LoginScreen(parentSetState: callBackSetState);
    }
    // If a saved file has been found
    if (Options.fileSaved == true) {
      return Region(latlong: Options.latlong, parentSetState: callBackSetState);
    }
    // If user has selected, but not saved a map
    if (Options.mapSaved == true) {
      return ConfirmationScreen(parentSetState: callBackSetState);
    }
    // If user has not began selecting the map, and no saved map has been found
    if (Options.mapSelected == true) {
      return CaptureMap(
          parentSetState: callBackSetState, updateLatLong: updateLatLongBounds);
    }

    // If the user has just logged in and performed no further actions
    return Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
              style: raisedButtonStyle,
              onPressed: () {
                Options.mapSaved = false;
                Options.savedImage = Uint8List(0);
                _onMapSelected();
              },
              child: const Text("Select Map"),
    ),
          //const CameraOrtho(),
          ],
        ));
  }

  @override
  Widget build(BuildContext context) {
    if (Options.savedImage.isEmpty) {
      Options.fileSaved = false;
      Options.mapSaved = false;
    }
    AppBar appbar = AppBar(
        title: const Text('Home'),
        actions: Options.fileSaved && Options.loggedIn
            ? [
                DropdownButton(
                  items: dropdownItems,
                  value: Options.currentRegion,
                  onChanged: (value) {
                    setState(() {
                      Options.currentRegion = value!;
                      Options.savedImage = File(
                              '${Options.directory.path}/regions/${Options.currentRegion.toString()}/image.png')
                          .readAsBytesSync();
                    });
                  },
                )
              ]
            : []);
    return WillPopScope(
        onWillPop: () async {
          final shouldPop = await showDialog<bool>(
            context: context,
            builder: (context) {
              return AlertDialog(
                title: const Text('Do you want to go back?'),
                actionsAlignment: MainAxisAlignment.spaceBetween,
                actions: [
                  TextButton(
                    onPressed: () {
                      Navigator.pop(context, false);
                    },
                    child: const Text('No'),
                  ),
                  TextButton(
                    onPressed: () {
                      SystemNavigator.pop(animated: true);
                    },
                    child: const Text('Yes'),
                  ),
                ],
              );
            },
          );
          return shouldPop!;
        },
        child: Scaffold(
          appBar: appbar,
          body: viewSelector(),
          bottomNavigationBar: BottomNavigationBar(
            items: const <BottomNavigationBarItem>[
              BottomNavigationBarItem(
                icon: Icon(Icons.home),
                label: 'Home',
              ),
              BottomNavigationBarItem(
                icon: Icon(Icons.account_circle),
                label: 'Mower',
              ),
              BottomNavigationBarItem(
                icon: Icon(Icons.alarm),
                label: 'Schedules',
              ),
            ],
            currentIndex: _selectedIndex,
            selectedItemColor: Colors.lightBlue[800],
            onTap: _onItemTapped,
          ),
        ));
  }
}

/// Regions properties and options used through the application
/// including renaming and retrieving region names, if a region is selected,
/// if the user is logged in
class Options {

  static int numberOfRegions = 0; /// Number of saved regions stored on the user's device
  static int currentRegion = 0; /// Currently selected region - one which will be used in editing
  static bool mapSelected = false; /// If a region has been selected
  static bool mapSaved = false; /// If a region has been saved
  static bool loggedIn = false; /// If the user is logged in

  static late Directory directory;
  static late permission_handler.PermissionStatus storagePermissionStatus;
  static late permission_handler.PermissionStatus locationPermissionStatus;

  static bool fileSaved = false;

  static Uint8List savedImage = Uint8List(0); /// Image of currently selected region to be displayed to the user

  static LatLngBounds latlong = LatLngBounds(
      southwest: const LatLng(0.0, 0.0), northeast: const LatLng(0.0, 0.0));

  /// Get the user defined named of a given region as these are stored in numerical order
  static String getRegionName(int i) {
    Directory dir = Directory("${Options.directory.path}/regions/$i");
    final List<FileSystemEntity> entities = dir.listSync().toList();
    final Iterable<File> files = entities.whereType<File>();

    for (var element in files) {
      if (element.ext == "txt") {
        return element.name;
      }
    }
    return "Home Lawn";
  }

  /// Renames the currently selected region to the users input
  static void renameRegion(int i, BuildContext context, void Function() parentSetState) {
    bool nameAlertReturn = false;
    String regionName = "";
    final GlobalKey<FormState> formKey = GlobalKey<FormState>();

    showDialog(
      barrierDismissible: false,
      context: context,
      builder: (BuildContext context) => AlertDialog(
        title: const Text("Enter a name for the new region"),
        content: Form(
          key: formKey,
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
                labelText: "Please name this region",
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
              if (formKey.currentState!.validate()) {
                formKey.currentState?.save();
                nameAlertReturn = true;
                if (nameAlertReturn) {
                  Directory dir = Directory("${Options.directory.path}/regions/$i");
                  final List<FileSystemEntity> entities = dir.listSync().toList();
                  final Iterable<File> files = entities.whereType<File>();

                  for (var element in files) {
                    if (element.ext == "txt") {
                      element.deleteSync();
                    }
                  }
                  File('${Options.directory.path}/regions/$i/$regionName.txt').createSync();
                }
                parentSetState();
                Navigator.of(context).pop();
              }
            },
          ),
        ],
        elevation: 24,
      ),
    );

  }
}

/// Handles user specific data namely their name, their cookie, and if this
/// is their first time using the application. This data is stored
/// in a file on their device
class User {

  static String name = "";
  // It was planned to develop a tutorial to walkthrough some functions
  // of the application if it was their first time using the app
  static bool firstUse = true;
  static String loginToken = "";

  static userFromFile(File file) {
    String jsonString = File(file.path).readAsStringSync();
    Map<String, dynamic> jsonEntry = jsonDecode(jsonString);
    name = jsonEntry['name'];
    firstUse = jsonEntry['firstUse'] == 'True';
    loginToken = jsonEntry['loginToken'];
  }

  static Map<String, dynamic> toJson() => {
    'name': name,
    'firstUse': firstUse ? "True" : "False",
    'loginToken': loginToken,
  };

  static userToFile() {
    Map<String, dynamic> toSave = toJson();
    if(!Directory("${Options.directory.path}/user").existsSync()) {
      Directory("${Options.directory.path}/user").createSync(recursive: true);
    }
    String filename = "${Options.directory.path}/user/properties.json";
    File(filename).createSync(recursive: true);
    File(filename).writeAsStringSync(toSave.toString());
  }

}
