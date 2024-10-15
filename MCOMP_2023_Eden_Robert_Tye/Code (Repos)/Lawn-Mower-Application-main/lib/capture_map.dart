import 'dart:convert';
import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:path_provider/path_provider.dart';
import 'package:screenshot/screenshot.dart';

import 'main.dart';

class CaptureMap extends StatefulWidget {
  const CaptureMap({super.key, required this.updateLatLong, required this.parentSetState});

  /// Callback function to refresh state of parent
  final void Function() parentSetState;
  /// Callback function to update the [LatLngBounds] used by [main] and
  /// [editor]
  final void Function(LatLngBounds latLngBounds) updateLatLong;

  @override
  _CaptureMapState createState() => _CaptureMapState();
}

class _CaptureMapState extends State<CaptureMap> {

  /// Sets the GoogleMap controller and listener
  void _onMapCreated(GoogleMapController cntlr) {
    googleMapController = cntlr;
  }

  /// Saves the current visible region of the map as an image and the bounds of
  /// the visible map to as a JSON file
  void _saveMapImage(LatLngBounds latLong) async {
    final String jsonLatLng = jsonEncode(latLong);

    final directory = await getApplicationDocumentsDirectory();

    await File(
            '${directory.path}/regions/${Options.currentRegion.toString()}/image.png')
        .create(recursive: true)
        .then((value) => value.writeAsBytes(Options.savedImage));
    await File(
            '${directory.path}/regions/${Options.currentRegion.toString()}/bounds.json')
        .create(recursive: true)
        .then((value) => value.writeAsString(jsonLatLng));
  }

  double screenHeight = 0;
  double screenWidth = 0;

  bool _snapShot = false;

  ScreenshotController screenshotController = ScreenshotController();
  late GoogleMapController googleMapController;

  final LatLng _initialcameraposition = const LatLng(20.5937, 78.9629);

  @override
  Widget build(BuildContext context) {
    screenWidth = MediaQuery.of(context).size.width;
    screenHeight = MediaQuery.of(context).size.height;

    return Stack(
      children: [
        GoogleMap(
          mapType: MapType.satellite,
          initialCameraPosition: CameraPosition(target: _initialcameraposition),
          onMapCreated: _onMapCreated,
          myLocationEnabled: _snapShot ? false : true,
        ),
        Positioned(
          top: screenHeight - (screenHeight / 3.5),
          left: screenWidth / 2 - 60,
          child: SizedBox(
            width: 120.0,
            height: 40.0,
            // Button to capture current view
            child: ElevatedButton(
              onPressed: () {
                _snapShot = true;
                widget.parentSetState();
                // Get a snapshot of the current area in view
                // snapshot being an image and bounds
                screenshotController
                    .capture()
                    .then((Uint8List? capturedImage) async {
                  var img = await googleMapController
                      .takeSnapshot()
                      .catchError((onError) {
                    if (kDebugMode) {
                      print(onError);
                    }
                  });
                  LatLngBounds visibleRegion = await googleMapController
                      .getVisibleRegion()
                      .catchError((onError) {
                    if (kDebugMode) {
                      print(onError);
                    }
                  });
                  widget.updateLatLong(visibleRegion);
                  // Save the image
                  Options.savedImage = img!;
                  _saveMapImage(visibleRegion);
                  // Map is selected as one was selected and saved
                  Options.mapSelected = true;
                  Options.mapSaved = true;
                  _snapShot = false;
                  widget.parentSetState();
                }).catchError((onError) {
                  if (kDebugMode) {
                    print(onError);
                  }
                });
              },
              child: const Text('Capture Map'),
            ),
          ),
        ),
      ],
    );
  }
}
