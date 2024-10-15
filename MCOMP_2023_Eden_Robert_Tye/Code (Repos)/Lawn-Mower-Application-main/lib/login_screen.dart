import 'dart:convert';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:email_validator/email_validator.dart';
import 'package:http/http.dart' as http;
import 'main.dart';


enum Request {
  login,
  signup
}

extension URL on Request {
  String get url {
    switch (this) {
      case Request.login:
        return "http://127.0.0.1:2004/api/signin";
      case Request.signup:
        return "http://127.0.0.1:2004/api/adduser";
    }
  }

  String get error {
    switch (this) {
      case Request.login:
        return 'Incorrect username or password, please try again';
      case Request.signup:
        return 'Username or password already taken, please try again';
    }
  }
}
/*

  /// TODO popup menu when signing up

 */
class LoginScreen extends StatefulWidget {
  const LoginScreen({super.key, required this.parentSetState});

  /// Callback function to refresh state of parent
  final void Function() parentSetState;

  @override
  _LoginScreenState createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  /// Login or Sign Up [req] is an enum which determines whether
  /// the action is logging in or signing up as the input and process
  /// is very similar
  void loginSignUp(Request req) async {
    // Validate the form fields are correct
    if (_formKey.currentState!.validate()) {
      _formKey.currentState?.save();
      // Make post request to server
      var response = await http.post(

          Uri.parse(req.url),
          headers: <String, String>{
            'Content-Type': 'application/json',
          },
          body: jsonEncode({
            'email': user,
            'pass': pass,
            'sname': lastName,
            'fname': firstName
          }));
      // If response is okay - no server error
      if (response.statusCode == 200) {
        Map<String, dynamic> responseBody =
        jsonDecode(response.body);
        // If success
        if (responseBody.containsKey("success")) {
          final cookies = response.headers["set-cookie"]!;
          User.loginToken = cookies.split(";")[0].split("=")[1].trim();
          await showDialog(
              context: context,
              builder: (ctx) => AlertDialog(
                title: const Text("Successful!"),
                actionsAlignment:
                MainAxisAlignment.spaceBetween,
                actions: [
                  TextButton(
                    onPressed: () {
                      Navigator.pop(context, false);
                    },
                    child: const Text('Okay'),
                  ),
                ],
              ));
          setState(() {
            Options.loggedIn = true;
            widget.parentSetState();
          });
        } else {
          showDialog(
              context: context,
              builder: (ctx) => AlertDialog(
                title: Text(req.error),
                actionsAlignment:
                MainAxisAlignment.spaceBetween,
                actions: [
                  TextButton(
                    onPressed: () {
                      Navigator.pop(context, false);
                    },
                    child: const Text('Okay'),
                  ),
                ],
              ));
        }
        // If no server error, but request was not successful i.e.,
        // valid connection but credentials were not valid
      } else {
        showDialog(
            context: context,
            builder: (ctx) => AlertDialog(
              title: const Text('Network Error, could not connect to server'),
              actionsAlignment:
              MainAxisAlignment.spaceBetween,
              actions: [
                TextButton(
                  onPressed: () {
                    Navigator.pop(context, false);
                  },
                  child: const Text('Okay'),
                ),
              ],
            ));
      }
    }
  }

  String user = "";
  String pass = "";
  String firstName = "";
  String lastName = "";

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(8.0),
      child: Form(
        key: _formKey,
        child: Column(mainAxisAlignment: MainAxisAlignment.center, children: [
          // First name
          Padding(
            padding: const EdgeInsets.all(10.0),
            child: TextFormField(
              onSaved: (String? value) {
                firstName = value!;
              },
              validator: (value) {
                if (value == null || value.isEmpty ) {
                  return "Please enter your first name";
                }
                return null;
              },
              decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: "First Name",
                  hintText: "Tye"),
            ),
          ),
          // Last name
          Padding(
            padding: const EdgeInsets.all(10.0),
            child: TextFormField(
              onSaved: (String? value) {
                lastName = value!;
              },
              validator: (value) {
                if (value == null ||value.isEmpty) {
                  return "Please enter your last name";
                }
                return null;
              },
              decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: "Last Name",
                  hintText: "Buckingham"),
            ),
          ),
          // Email
          Padding(
            padding: const EdgeInsets.all(10.0),
            child: TextFormField(
              onSaved: (String? value) {
                user = value!;
              },
              validator: (value) {
                if (value == null ||
                    value.isEmpty ||
                    !EmailValidator.validate(value)) {
                  return "Please enter a valid email";
                }
                return null;
              },
              decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: "Email",
                  hintText: "lawnmower@email.com"),
            ),
          ),
          // Password
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: TextFormField(
              onSaved: (String? value) {
                pass = value!;
              },
              validator: (String? value) {
                if (value == null || value.isEmpty) {
                  return 'Please enter a password';
                }
                return null;
              },
              obscureText: true,
              decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: "Password",
                  hintText: "Account"),
            ),
          ),
          Row(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
            ElevatedButton(
                onPressed: kDebugMode
                    ? () {
                        setState(() {
                          Options.loggedIn = true;
                          widget.parentSetState();
                        });
                      }
                    : () async {
                        loginSignUp(Request.login);
                      },
                child: const Text("Log in")),
            ElevatedButton(
                onPressed: kDebugMode
                    ? () {
                  setState(() {
                    Options.loggedIn = true;
                    widget.parentSetState();
                  });
                }
                    : () async {
                  loginSignUp(Request.signup);
                },
                child: const Text("Sign up")),
          ])
        ]),
      ),
    );
  }
}
