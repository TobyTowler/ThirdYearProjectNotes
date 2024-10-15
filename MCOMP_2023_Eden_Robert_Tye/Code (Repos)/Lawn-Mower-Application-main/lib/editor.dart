import 'dart:collection';
import 'dart:convert';
import 'dart:core';
import 'dart:math';
import 'dart:io';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:lawnmower/mower.dart';
import 'package:lawnmower/tutorial_alert.dart';
import 'package:path_provider/path_provider.dart';
import 'package:rflutter_alert/rflutter_alert.dart';
import "package:lawnmower/main.dart" as main;
import 'package:http/http.dart' as http;
import 'package:dart_jts/dart_jts.dart';

import 'main.dart';

/*
TODO:
      * Be able to select shapes
      * Comments
 */

class Editor extends StatelessWidget {
  const Editor({super.key});

  static const String _title = 'Edit';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: _title,
      initialRoute: '/editor',
      routes: {
        '/editor': (context) => const EditorStatefulWidget(),
        '/mower': (context) => const Mower(),
        '/home': (context) => const main.MowerApp(),
      },
    );
  }
}

class EditorStatefulWidget extends StatefulWidget {
  const EditorStatefulWidget({super.key});

  @override
  State<EditorStatefulWidget> createState() => _EditorStatefulWidgetState();
}

class _EditorStatefulWidgetState extends State<EditorStatefulWidget> {

  late List<double> coords;
  late LatLong ltlg;
  Perimeter perimeter = Perimeter(
      points: List<Point>.empty(growable: true),
      gpsPoints: List<Point>.empty(growable: true),
      latLong: LatLong(south: 0.0, west: 0.0, north: 0.0, east: 0.0));
  List<NoGo> noGos = List<NoGo>.empty(growable: true);

  int _selectedIndex = 0;
  String selectedMap = "Home 1";

  List<DropdownMenuItem<String>> get dropdownItems {
    List<DropdownMenuItem<String>> menuItems = [
      const DropdownMenuItem(value: "Home 1", child: Text("Home 1")),
    ];
    return menuItems;
  }

  List<DropdownMenuItem<String>> get zoomDrawItems {
    List<DropdownMenuItem<String>> menuItems = [
      const DropdownMenuItem(
          value: "Draw",
          child: Text(
            "Draw",
            style: TextStyle(color: Colors.white),
          )),
      const DropdownMenuItem(
          value: "Zoom",
          child: Text(
            "Zoom",
            style: TextStyle(color: Colors.white),
          )),
    ];
    return menuItems;
  }

  List<DropdownMenuItem<String>> get perimeterNoGoItems {
    List<DropdownMenuItem<String>> menuItems = [
      const DropdownMenuItem(
          value: "Perimeter",
          child: Text(
            "Perimeter",
            style: TextStyle(color: Colors.white),
          )),
      const DropdownMenuItem(
          value: "No-Go",
          child: Text(
            "No-Go",
            style: TextStyle(color: Colors.white),
          )),
    ];
    return menuItems;
  }

  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index;
    });
    if (index == 0) {
      Navigator.popAndPushNamed(context, '/home');
    }
    if (index == 1) {
      Navigator.popAndPushNamed(context, '/mower');
    }
  }
  // Related to unfinished tutorial
  void _removeTutorialAlert() {
    EditorTutorial.tutorial.removeLast();
    if (EditorTutorial.tutorial.isEmpty) {
      User.firstUse = false;
      User.userToFile();
    }
    setState(() {});
  }

  /// Send the perimeter and no-go zones GPS points to the server
  Future<int> sendPoints(
      String name, String notes, Perimeter perimeter, List<NoGo> noGos) async {
    final response = await http.post(
      Uri.parse('http://127.0.0.1:2004/api/addarea'),
      headers: <String, String>{
        'Content-Type': 'application/json',
        'Cookie': "session=${User.loginToken}",
      },
      body: jsonEncode({
        "name": Options.getRegionName(Options.currentRegion),
        "notes": "",
        "area_coords": perimeter.sendJson(),
        "nogo_zones": noGos.map((e) => e.sendJson(noGos)).toList(),
      }),
    );
    return response.statusCode;
  }

  /// Save the perimeter and no-go zones GPS points to the user's device
  /// in two JSON files 'perimeter.json' and 'no-gos.json'
  Future<void> savePoints(Perimeter perimeter, List<NoGo> noGos) async {
    Directory directory = await getApplicationDocumentsDirectory();
    File perimeterFile = File(
        '${directory.path}/regions/${Options.currentRegion.toString()}/perimeter.json');
    File noGosFile = File(
        '${directory.path}/regions/${Options.currentRegion.toString()}/no-gos.json');

    String perimeterJson = jsonEncode(perimeter);
    String noGoJson = jsonEncode(noGos);

    await perimeterFile.writeAsString(perimeterJson);
    await noGosFile.writeAsString(noGoJson);

    return;
  }

  /// Checks if the perimeter and no-go GPS point data is present in the current
  /// region's folder
  bool pointFilesExists() {
    if (!File(
            '${Options.directory.path}/regions/${Options.currentRegion.toString()}/perimeter.json')
        .existsSync()) {
      return false;
    }
    if (!File(
            '${Options.directory.path}/regions/${Options.currentRegion.toString()}/no-gos.json')
        .existsSync()) {
      return false;
    }
    return true;
  }

  /// Check if the geo-bounds data of the currently selected region is present
  bool boundsFileExists() {
    if (!File(
            '${Options.directory.path}/regions/${Options.currentRegion.toString()}/bounds.json')
        .existsSync()) {
      return false;
    }

    return true;
  }

  /// Load the no-go(s), perimeter, and bounds GPS points
  List loadPoints(Perimeter perimeter, List<NoGo> noGos, Directory directory) {
    File perimeterFile = File(
        '${directory.path}/regions/${Options.currentRegion.toString()}/perimeter.json');
    File noGosFile = File(
        '${directory.path}/regions/${Options.currentRegion.toString()}/no-gos.json');

    final perimeterData = jsonDecode(perimeterFile.readAsStringSync());
    // Nogos is a list of maps
    List<dynamic> noGoData = jsonDecode(noGosFile.readAsStringSync());

    // Data contains GPS data (coords) and x, y points (points)
    // coords for server planning and points for displaying on app
    String coords = perimeterData['co-ords'];
    String points = perimeterData['points'];

    List<String> listCoords =
        coords.replaceAll("]", "").replaceAll("[", "").split(',');
    List<String> listPoints =
        points.replaceAll("]", "").replaceAll("[", "").split(',');
    perimeter = Perimeter(
        points: List<Point>.empty(growable: true),
        gpsPoints: List<Point>.empty(growable: true),
        latLong: LatLong(
            south: double.parse(perimeterData['latlong']['south']),
            west: double.parse(perimeterData['latlong']['west']),
            north: double.parse(perimeterData['latlong']['north']),
            east: double.parse(perimeterData['latlong']['east'])));

    noGos = List<NoGo>.empty(growable: true);

    for (int i = 0; i < listCoords.length - 1; i += 2) {
      perimeter.gpsPoints.add(Point(
          x: double.parse(listPoints[i]), y: double.parse(listPoints[i + 1])));
      perimeter.points.add(Point(
          x: double.parse(listCoords[i]), y: double.parse(listCoords[i + 1])));
    }

    for (int i = 0; i < noGoData.length; i++) {
      LatLong latlong = LatLong(
          south: double.parse(noGoData[i]['latlong']['south']),
          west: double.parse(noGoData[i]['latlong']['west']),
          north: double.parse(noGoData[i]['latlong']['north']),
          east: double.parse(noGoData[i]['latlong']['east']));

      noGos.add(NoGo(
          points: List<Point>.empty(growable: true),
          gpsPoints: List<Point>.empty(growable: true),
          latLong: latlong));

      List<String> listCoords = noGoData[i]['co-ords']
          .replaceAll("]", "")
          .replaceAll("[", "")
          .split(',');
      List<String> listPoints = noGoData[i]['points']
          .replaceAll("]", "")
          .replaceAll("[", "")
          .split(',');
      for (int j = 0; j < listCoords.length - 1; j += 2) {
        noGos[i].points.add(Point(
            x: double.parse(listCoords[j]),
            y: double.parse(listCoords[j + 1])));
      }
      for (int j = 0; j < listPoints.length - 1; j += 2) {
        noGos[i].gpsPoints.add(Point(
            x: double.parse(listPoints[j]),
            y: double.parse(listPoints[j + 1])));
      }
    }
    return [perimeter, noGos];
  }

  // Certain options are only allowed, or not allowed, when perimeter is selected
  bool isPerimeter = true;

  var perimeterNogoText = "Switch to Perimeter";
  bool perSaved = false;
  Random rdm = Random();

  _EditorStatefulWidgetState() {
    // If points (xy and gps) load them
    if (pointFilesExists()) {
      List results = loadPoints(perimeter, noGos, Options.directory);
      perimeter = results[0];
      noGos = results[1];
      ltlg = perimeter.latLong;
    } else {
      // If only the boundary exists - no drawings were made by the user
      if (boundsFileExists()) {
        File boundsFile = File(
            '${Options.directory.path}/regions/${Options.currentRegion.toString()}/bounds.json');

        List<dynamic> boundsFileData =
            jsonDecode(boundsFile.readAsStringSync());
        List<dynamic> southWest = boundsFileData[0];
        List<dynamic> northEast = boundsFileData[1];
        ltlg = LatLong(
            south: southWest[0],
            west: southWest[1],
            north: northEast[0],
            east: northEast[1]);
      } else {
        // If not files exists then use the currently selected one as we
        // must have just come from selecting one, ...
        Map<String, dynamic> coords =
            LatLong.readString(Options.latlong.toJson().toString());
        ltlg = LatLong(
            south: coords["south"]!,
            west: coords["west"]!,
            north: coords["north"]!,
            east: coords["east"]!);
      }
      // ... and initialise empty perimeter and nogos
      perimeter = Perimeter(
          points: List<Point>.empty(growable: true),
          gpsPoints: List<Point>.empty(growable: true),
          latLong: ltlg);

      noGos = List.filled(
          1,
          NoGo(
              points: List<Point>.empty(growable: true),
              gpsPoints: List<Point>.empty(growable: true),
              latLong: ltlg),
          growable: true);
    }
  }

  /// Only active if a perimeter has been drawn
  bool saveButtonActive() {
    if (perimeter.points.isEmpty) {
      return false;
    }
    return true;
  }

  /// Only active if there are points to delete
  bool deleteButtonActive() {
    if (isPerimeter && perimeter.points.isEmpty) {
      return false;
    }
    if (!isPerimeter && noGos.isEmpty) {
      return false;
    }
    if (!isPerimeter && noGos.last.points.isEmpty) {
      return false;
    }
    return true;
  }

  /// Only active if there are points to undo
  bool undoButtonActive() {
    if (isPerimeter && perimeter.points.isEmpty) {
      return false;
    }
    if (!isPerimeter && noGos.isEmpty) {
      return false;
    }
    if (!isPerimeter && noGos.last.points.isEmpty) {
      return false;
    }
    return true;
  }

  @override
  void initState() {
    super.initState();
    try {
      loadPoints(perimeter, noGos, Options.directory);
    } catch (FileSystemException) {
      ;
    }
    if (User.firstUse) {
      EditorTutorial.initQueue(_removeTutorialAlert);
    }
    setState(() {});
  }

  double imageScale = 1;
  final TransformationController _transformationController =
      TransformationController();

  bool draw = false; // Drawing and zooming are not allowed at the same time

  Offset imageOffset = const Offset(0, 0);
  String zoomDrawValue = "Draw";
  String perimeterNoGoValue = "Perimeter";

  @override
  Widget build(BuildContext context) {
    perimeter.latLong.addContext(context);
    perimeter.latLong.calculateDimensions();

    for (var element in noGos) {
      element.latLong.addContext(context);
      element.latLong.calculateDimensions();
    }
    AppBar appbar = AppBar(title: const Text('Edit Map'),
        actions: [
      SizedBox(
        width: MediaQuery.of(context).size.width / 7.75,
        child: ElevatedButton(
            onPressed: saveButtonActive()
                ? () async {
                    setState(() {
                      if (isPerimeter) {
                        perSaved = true;
                      }
                    });
                    if (!kDebugMode) {
                      await sendPoints(
                          Options.getRegionName(Options.currentRegion),
                          "",
                          perimeter,
                          noGos);
                    }
                    await savePoints(perimeter, noGos);
                  }
                : null,
            child: const Icon(Icons.save)),
      ),
      SizedBox(
        width: MediaQuery.of(context).size.width / 7.75,
        child: ElevatedButton(
            onPressed: isPerimeter || !noGos.last.points.isNotEmpty
                ? null
                : () {
                    noGos.add(NoGo(
                        points: List<Point>.empty(growable: true),
                        gpsPoints: List<Point>.empty(growable: true),
                        latLong: ltlg));
                  },
            child: const Icon(Icons.add)),
      ),
      Padding(
        padding: const EdgeInsets.all(8.0),
        child: DropdownButton(
          dropdownColor: Colors.blue,
          onChanged: (value) {
            setState(() {
              value == "Perimeter" ? isPerimeter = true : isPerimeter = false;
              perimeterNoGoValue = value!;
            });
          },
          value: perimeterNoGoValue,
          items: perimeterNoGoItems,
        ),
      ),
      Padding(
        padding: const EdgeInsets.all(8.0),
        child: DropdownButton(
          dropdownColor: Colors.blue,
          onChanged: (value) {
            setState(() {
              value == "Draw" ? draw = true : draw = false;
              zoomDrawValue = value!;
            });
          },
          value: zoomDrawValue,
          items: zoomDrawItems,
        ),
      ),
      SizedBox(
        width: MediaQuery.of(context).size.width / 7.75,
        child: ElevatedButton(
          onPressed: deleteButtonActive()
              ? () {
                  setState(() {
                    if (isPerimeter && perimeter.points.isNotEmpty) {
                      perimeter.clear();
                      perSaved = false;
                    } else if (noGos.isNotEmpty) {
                      noGos.removeLast();
                    } else {
                      Alert(
                          context: context,
                          type: AlertType.info,
                          title: "No more to remove",
                          desc: "You have no more 'no-go' zones to delete",
                          buttons: []).show();
                    }
                  });
                }
              : null,
          child: const Icon(Icons.delete),
        ),
      ),
      SizedBox(
        width: MediaQuery.of(context).size.width / 7.75,
        child: ElevatedButton(
            onPressed: undoButtonActive()
                ? () {
                    isPerimeter
                        ? {perimeter.points.removeLast(), perSaved = false}
                        : noGos.last.points.removeLast();
                  }
                : null,
            child: const Icon(Icons.undo)),
      ),
    ]);
    ltlg.addContext(context);
    ltlg.calculateDimensions();
    int keyUpdater = 0;
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
                      SystemNavigator.pop(animated: true);
                    },
                    child: const Text('Yes'),
                  ),
                  TextButton(
                    onPressed: () {
                      Navigator.pop(context, false);
                    },
                    child: const Text('No'),
                  ),
                ],
              );
            },
          );
          return shouldPop!;
        },
        child: Scaffold(
          appBar: appbar,
          body: Stack(
            children: [
              InteractiveViewer(
                panEnabled: draw ? false : true,
                scaleEnabled: draw ? false : true,
                minScale: 1,
                maxScale: draw ? imageScale : 2.5,
                transformationController: _transformationController,
                child: Stack(children: [
                  SizedBox(
                    width: 0,
                    height: 0,
                    child: DropdownButtonFormField<String>(
                        onChanged: (value) {}, items: const []),
                  ),
                  GestureDetector(
                    child: CustomPaint(
                      painter: UserDrawingLine(per: perimeter, nogos: noGos),
                      foregroundPainter:
                          UserDrawingLine(per: perimeter, nogos: noGos),
                      key: ValueKey(keyUpdater),
                      child: Image.memory(Options.savedImage),
                    ),
                    onTapDown: (event) {
                      if (draw) {
                        setState(() {
                          if (isPerimeter &&
                              perSaved &&
                              perimeter.points.isNotEmpty) {
                            Alert(
                                context: context,
                                type: AlertType.info,
                                title: "Perimeter",
                                desc:
                                    "You can only have one perimeter, please click the 'Reset' "
                                    "button to delete the currently saved perimeter.",
                                buttons: []).show();
                          } else {
                            if (noGos.isEmpty) {
                              noGos.add(NoGo(
                                  points: List<Point>.empty(growable: true),
                                  gpsPoints: List<Point>.empty(growable: true),
                                  latLong: ltlg));
                            }
                            if (isPerimeter) {
                              if (!perimeter.addPoint(event.localPosition.dx,
                                  event.localPosition.dy)) {
                                setState(() {
                                  Alert(
                                      context: context,
                                      type: AlertType.info,
                                      title: "Intersecting Lines",
                                      desc:
                                          "Lines for perimeters and no-go zones must not intersect",
                                      buttons: []).show();
                                });
                              }
                            } else {
                              if (!noGos.last.addPoint(event.localPosition.dx,
                                  event.localPosition.dy)) {
                                setState(() {
                                  Alert(
                                      context: context,
                                      type: AlertType.info,
                                      title: "Intersecting Lines",
                                      desc:
                                          "Lines for perimeters and no-go zones must not intersect",
                                      buttons: []).show();
                                });
                              }
                            }
                            keyUpdater = rdm.nextInt(100);
                          }
                        });
                      }
                    },
                  )
                ]),
              ),
              User.firstUse ? EditorTutorial.tutorial.last : Container(),
            ],
          ),
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

/// x and y point, used for drawing points on the screen
class Point {
  double x, y;

  Point({required this.x, required this.y});

  Offset getOffset() {
    return Offset(x, y);
  }

  Map<String, double> toJson() => {"x": x, "y": y, "z": 0.0};

  List<double> toList() {
    return [x, y, 0.0];
  }

  @override
  String toString() {
    return '$x, $y';
  }
}

/// No-go zone, an area which the user does not want their robot to go
class NoGo {
  List<Point> points; // x, y for drawing on screen
  List<Point> gpsPoints; // gps for server coverage planning

  LatLong latLong;

  NoGo({required this.points, required this.gpsPoints, required this.latLong});

  // Add new point and connect line between it and previous point
  bool addPoint(double x, double y) {
    RobustLineIntersector lineIntersector = RobustLineIntersector();
    for (int i = 0; i < points.length - 1; i++) {
      lineIntersector.computeIntersection(
          Coordinate(points.last.x, points.last.y),
          Coordinate(x, y),
          // New line
          Coordinate(points[i].x, points[i].y),
          Coordinate(points[i + 1].x, points[i + 1].y) // Other line
          );
      if (lineIntersector.hasIntersection() &&
          !lineIntersector.isCollinear() &&
          !lineIntersector.isEndPoint()) {
        return false;
      }
    }
    points.add(Point(x: x, y: y));
    var gps = latLong.calculatePosition(x, y);
    gpsPoints.add(Point(x: gps[1], y: gps[0]));
    return true;
  }

  List<List<double>> sendJson(List<NoGo> nogos) {
    return gpsPoints.map((e) => e.toList()).toList();
  }

  Map toJson() => {
        'length': gpsPoints.length.toString(),
        'points': gpsPoints.toString(),
        'co-ords': points.toString(),
        'latlong': latLong.toJson()
      };

  void clear() {
    points = List<Point>.empty(growable: true);
    gpsPoints = List<Point>.empty(growable: true);
  }

  String sendString() {
    String gpsPointsString = "";
    for (var element in gpsPoints) {
      if (element == gpsPoints.last) {
        break;
      }
      gpsPointsString += "[$element]";
    }
    return gpsPointsString;
  }

  @override
  String toString() {
    String pointsString = "";
    String gpsPointsString = "";
    for (var element in points) {
      pointsString += element.toString();
    }
    for (var element in gpsPoints) {
      gpsPointsString += element.toString();
    }
    return ("Points: $pointsString : GPS Points: $gpsPointsString");
  }
}

/// The user defined perimeter of a given region - where the robot must stay within
class Perimeter {
  List<Point> points;
  List<Point> gpsPoints;

  LatLong latLong;

  Perimeter(
      {required this.points, required this.gpsPoints, required this.latLong});

  bool addPoint(double x, double y) {
    RobustLineIntersector lineIntersector = RobustLineIntersector();
    for (int i = 0; i < points.length - 1; i++) {
      lineIntersector.computeIntersection(
          Coordinate(points.last.x, points.last.y),
          Coordinate(x, y),
          // New line
          Coordinate(points[i].x, points[i].y),
          Coordinate(points[i + 1].x, points[i + 1].y) // Other line
          );
      if (lineIntersector.hasIntersection() &&
          !lineIntersector.isCollinear() &&
          !lineIntersector.isEndPoint()) {
        return false;
      }
    }
    points.add(Point(x: x, y: y));
    var gps = latLong.calculatePosition(x, y);
    gpsPoints.add(Point(x: gps[1], y: gps[0]));

    return true;
  }

  List<List<double>> sendJson() {
    return gpsPoints.map((e) => e.toList()).toList();
  }

  String sendString() {
    String gpsPointsString = "";
    for (var element in gpsPoints) {
      gpsPointsString += "[$element]";
    }
    return gpsPointsString;
  }

  Map toJson() => {
        'length': gpsPoints.length.toString(),
        'points': gpsPoints.toString(),
        'co-ords': points.toString(),
        'latlong': latLong.toJson()
      };

  void clear() {
    points = List<Point>.empty(growable: true);
    gpsPoints = List<Point>.empty(growable: true);
  }

  @override
  String toString() {
    String pointsString = "";
    String gpsPointsString = "";
    for (var element in points) {
      pointsString += element.toString();
    }
    for (var element in gpsPoints) {
      gpsPointsString += element.toString();
    }
    return ("Points: $pointsString : GPS Points: $gpsPointsString");
  }
}

/// Defines the GPS bounds of a region and determines mapping of GPS
/// to on screen x, y
class LatLong {
  double width = 0, height = 0, south, west, north, east;
  double screenWidth = 0, screenHeight = 0;
  double xRatio = 0, yRatio = 0; // ratio of GPS bounds to screen bounds

  LatLong(
      {required this.south,
      required this.west,
      required this.north,
      required this.east});

  Map toJson() => {
        'south': south.toString(),
        'north': north.toString(),
        'west': west.toString(),
        'east': east.toString()
      };

  /// Calculates the ratio of GPS bounds to screen bounds. [addContext] must
  /// be executed first
  void calculateDimensions() {
    width = (east - west).abs();
    height = (south - north).abs();

    xRatio = width / screenWidth;
    yRatio = height / screenHeight;
  }

  /// Context is required (screen dimensions) to determine ratios for [calculateDimensions]
  void addContext(var context) {
    screenWidth = MediaQuery.of(context).size.width;
    screenHeight = MediaQuery.of(context).size.height -
        kToolbarHeight -
        MediaQuery.of(context).padding.top -
        kBottomNavigationBarHeight;
  }

  /// Given a the screen coordinates tapped by the user, return the
  /// corresponding GPS coordinates based on the ratio.
  /// [calculateDimensions] and [addContext] must be executed first for
  /// the required values to be stored
  List calculatePosition(var x, var y) {
    var convertedX = x * xRatio;
    var convertedY = y * yRatio;

    var xGPS = convertedX + west;
    var yGPS = north - convertedY;

    return [xGPS, yGPS];
  }

  static Map<String, double> readString(String str) {
    str = str.replaceAll("]", "");
    str = str.replaceAll("[", "");
    List<String> splitStr = str.split(',');
    return {
      "south": double.parse(splitStr[0]),
      "west": double.parse(splitStr[1]),
      "north": double.parse(splitStr[2]),
      "east": double.parse(splitStr[3])
    };
  }
}

/// Handles drawing the lines between points which the user has tapped.
/// Only straight lines are currently considered.
class UserDrawingLine extends CustomPainter {
  final Perimeter per;
  final List<NoGo> nogos;

  UserDrawingLine({required this.per, required this.nogos});

  @override
  void paint(Canvas canvas, Size size) {
    for (int i = 0; i < per.points.length - 1; i++) {
      final paint = Paint()
        ..color = Colors.deepPurpleAccent
        ..strokeWidth = 2;
      canvas.drawLine(
          per.points[i].getOffset(), per.points[i + 1].getOffset(), paint);
    }
    for (int i = 0; i < nogos.length; i++) {
      for (int j = 0; j < nogos[i].points.length - 1; j++) {
        final paint = Paint()
          ..color = Colors.red
          ..strokeWidth = 2;
        canvas.drawLine(nogos[i].points[j].getOffset(),
            nogos[i].points[j + 1].getOffset(), paint);
      }
    }
  }

  @override
  bool shouldRepaint(CustomPainter oldDelegate) {
    return false;
  }
}

/// Incomplete feature. Would give a short tutorial on the options when editing
/// a region's perimeter and no-gos. Would explain some of the restraints imposed
/// such as requiring a perimeter.
class EditorTutorial {
  static late Queue<TutorialAlert> tutorial;
  static late final void Function() removeSelfFromQueue;

  static initQueue(void Function() removeFromQueue) {
    removeSelfFromQueue = removeFromQueue;
    tutorial = Queue<TutorialAlert>();
    tutorial.addAll([
      TutorialAlert(
          removeSelfFromQueue: removeSelfFromQueue,
          text: "This is the delete button",
          top: 10.0,
          left: 10.0),
      TutorialAlert(
          removeSelfFromQueue: removeSelfFromQueue,
          text: "This is the undo button",
          top: 50,
          left: 50)
    ]);
    User.firstUse = false;
  }
}
