import 'dart:async';
import 'dart:convert';
import 'dart:core';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:sensors_plus/sensors_plus.dart';


class CameraOrtho extends StatefulWidget {
  const CameraOrtho({super.key});

  @override
  _CameraOrthoState createState() => _CameraOrthoState();
}

class _CameraOrthoState extends State<CameraOrtho> {
  Map<String, dynamic> _cameraInfo = <String, dynamic>{};

  static const MethodChannel _channel =
  MethodChannel('camera_characteristics');

  @override
  void initState() {
    super.initState();
    _streamSubscriptions.add(
      gyroscopeEvents.listen(
            (GyroscopeEvent event) {
          setState(() {
            _gyroscopeValues = <double>[event.x, event.y, event.z];
          });
        },
      ),
    );
    init();
  }

  List<double>? _gyroscopeValues;
  final _streamSubscriptions = <StreamSubscription<dynamic>>[];

  Future<void> init() async {

    Map<String, dynamic> cameraInfo = jsonDecode(await _channel.invokeMethod('getCameraCharacteristics'))[0];

    if (!mounted) return;

    setState(() {
      _cameraInfo = cameraInfo;
    });
  }

  @override
  Widget build(BuildContext context) {
    final gyroscope =
    _gyroscopeValues?.map((double v) => v.toStringAsFixed(1)).toList();
    init();
    return Center(child:
      _cameraInfo.isEmpty ? Container() : Text(_cameraInfo["SENSOR_INFO_PHYSICAL_SIZE"] + " : " +
          _cameraInfo["LENS_INFO_AVAILABLE_FOCAL_LENGTHS"] + " : " +
          _cameraInfo["ORIENTATION"])
    );
  }
}
