import 'package:flutter/material.dart';

class TutorialAlert extends StatefulWidget {
  TutorialAlert({ super.key, required this.removeSelfFromQueue, required this.text,
  required this.top, required this.left});

  String text;
  final void Function() removeSelfFromQueue;
  final double top;
  final double left;

  @override
  _TutorialAlertState createState() => _TutorialAlertState();
}

class _TutorialAlertState extends State<TutorialAlert> {
  @override
  Widget build(BuildContext context) {
    return Positioned(
      top: widget.top,
      left: widget.left,
      child: Flex(
        mainAxisSize: MainAxisSize.min,
        direction: Axis.vertical,
        children: [
          Flexible(
            fit: FlexFit.loose,
              child: Opacity(
                opacity: 0.8,
                child: DecoratedBox(
                  decoration: BoxDecoration(
                    color: Colors.grey,
                    borderRadius: BorderRadius.circular(8.0),
                    border: Border.all(
                      color: Colors.black45,
                    )
                  ),
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Column(
                      children: [
                        Text(widget.text),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.end,
                          children: [
                            Padding(
                              padding: const EdgeInsets.only(top: 10.0),
                              child: ElevatedButton(
                                onPressed: () {
                                  widget.removeSelfFromQueue();
                                },
                                child: const Text("Next"),
                              ),
                            )
                          ],
                        )
                      ],
                    ),
                  ),
                ),
              )
          ),
        ]
      ),
    );
  }
}
