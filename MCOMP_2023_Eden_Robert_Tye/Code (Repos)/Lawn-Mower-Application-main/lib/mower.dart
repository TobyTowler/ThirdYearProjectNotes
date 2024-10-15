import 'dart:io';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:lawnmower/editor.dart';
import 'package:lawnmower/main.dart' as main;

import 'main.dart';

class Mower extends StatelessWidget {
  const Mower({ super.key });

  static const String _title = 'Mower';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: _title,
      initialRoute: '/mower',
      routes: {
        '/editor': (context) => const Editor(),
        '/mower': (context) => const MowerStatefulWidget(),
        '/home': (context) => const main.MowerApp(),
      },
    );
  }
}

class MowerStatefulWidget extends StatefulWidget {

  const MowerStatefulWidget({super.key});

  @override
  State<MowerStatefulWidget> createState() => _MowerStatefulWidgetState();
}

class _MowerStatefulWidgetState extends State<MowerStatefulWidget> {

  int _selectedIndex = 1;

  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index;
    });
    if (index == 0) {
      Navigator.popAndPushNamed(context, '/home');
    }
  }

  void poleRobot() {
    /// TODO get details from robot and update values
    /// have this running on a timer
  }

  /// Returns percentage of route complete based simply on number
  /// of complete nodes.
  double percentComplete() {
    // More suitable method should take use total distance and distance travelled.
    if(totalNodes == 0) {
      return 0;
    }
    return currentNode / totalNodes;
  }
  /// Given percentage of route complete and intended travel speed, produces
  /// an approximate finish time for the current route
  double estimateFinish() {
    return (routeLength * percentComplete()) / 2; // mph, returns in hours
  }

  @override
  void initState() {
    super.initState();
    // TODO pole robot
    setState(() {

    });
  }

  double progress = 0.0;
  int currentNode = 0;
  int totalNodes = 0;
  int routeLength = 0;
  double batteryLevel = 0.0;

  // Much of this is currently incomplete as it was not a priority, but
  // rather a 'could' have feature, would include showing robot's current
  // location, progress, route driven, etc., to the user
  @override
  Widget build(BuildContext context) {

    AppBar appbar = AppBar(title: const Text('Mower'), actions: const []);

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
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              /// TODO overlay route and progress onto map
              Image.file(
                  File(
                  '${Options.directory.path}/regions/${Options.currentRegion.toString()}/image.png'),
                height: MediaQuery.of(context).size.height * 0.45,
              ),
              /// TODO map current region to a name given by the user
              Text("Working on region ${Options.currentRegion + 1} / ${Options.numberOfRegions}", style: const TextStyle(fontSize: 20,),),
              Text("${percentComplete()}% Complete", style: const TextStyle(fontSize: 20,),),
              Text("Estimated finish time is ${estimateFinish()} hours", style: const TextStyle(fontSize: 20,),),
              SizedBox(
                width: MediaQuery.of(context).size.width * 0.75,
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    ElevatedButton(onPressed: () {}, child: const Text("Start")),
                    ElevatedButton(onPressed: () {}, child: const Text("Pause")),
                    ElevatedButton(onPressed: () {}, child: const Text("Stop")),
                  ],
                ),
              )
            ],
          ),
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
      ),
    );
  }
}
