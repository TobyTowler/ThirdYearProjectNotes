import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';

import 'main.dart';

class ConfirmationScreen extends StatefulWidget {
  const ConfirmationScreen({super.key, required this.parentSetState});

  /// Callback function to refresh state of parent
  final void Function() parentSetState;

  @override
  _ConfirmationScreenState createState() => _ConfirmationScreenState();
}

class _ConfirmationScreenState extends State<ConfirmationScreen> {
  double screenHeight = 0;
  double screenWidth = 0;

  @override
  Widget build(BuildContext context) {
    screenWidth = MediaQuery.of(context).size.width;
    screenHeight = MediaQuery.of(context).size.height;
    return Stack(
      children: [
        Image.memory(Options.savedImage),
        Positioned(
            top: screenHeight - (screenHeight / 3.5),
            left: screenWidth / 2 - 110,
            child: SizedBox(
                width: 100.0,
                height: 40.0,
                child: ElevatedButton(
                  // Delete the just selected and saved snapshot
                  // makes more sense to save after confirmation, this is
                  // just a relic of previous versions
                  // TODO change this to save after confirmation instead
                    onPressed: () async {
                      await Directory(
                              '${Options.directory.path}/regions/${Options.currentRegion.toString()}')
                          .delete(recursive: true)
                          .catchError((onError) {
                        if (kDebugMode) {
                          print(onError);
                        }
                      });

                      Options.mapSelected = false;
                      Options.mapSaved = false;
                      Options.fileSaved = false;
                      Options.savedImage = Uint8List(0);
                      widget.parentSetState();
                    },
                    child: const Text("Try Again")))),
        Positioned(
            top: screenHeight - (screenHeight / 3.5),
            left: screenWidth / 2 + 10,
            child: SizedBox(
                width: 100.0,
                height: 40.0,
                child: ElevatedButton(
                    onPressed: () {
                      Options.fileSaved = true;
                      Options.mapSaved = true;
                      Options.mapSelected = true;
                      widget.parentSetState();
                    },
                    child: const Text("Confirm")))),
      ],
    );
  }
}
