// Dart code demonstrating different layout structures using Row, Column, and Stack widgets.
// You can run this code in an online Dart/Flutter compiler like DartPad (https://dartpad.dev/)

import 'package:flutter/material.dart';

void main() => runApp(LayoutDemoApp());

class LayoutDemoApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Layout Demo',
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(title: Text('Row, Column, and Stack Demo')),
        body: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text('Row Example:',
                  style: TextStyle(fontWeight: FontWeight.bold)),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  Icon(Icons.star, color: Colors.blue),
                  Icon(Icons.favorite, color: Colors.red),
                  Icon(Icons.thumb_up, color: Colors.green),
                ],
              ),
              SizedBox(height: 16),
              Text('Column Example (Grocery List):',
                  style: TextStyle(fontWeight: FontWeight.bold)),
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text('• Apples'),
                  Text('• Bread'),
                  Text('• Milk'),
                  Text('• Eggs'),
                  Text('• Rice'),
                ],
              ),
              SizedBox(height: 16),
              Text('Stack Example:',
                  style: TextStyle(fontWeight: FontWeight.bold)),
              Container(
                width: 200,
                height: 120,
                color: Colors.orange[100],
                child: Stack(
                  children: [
                    Container(
                      width: 200,
                      height: 120,
                      color: Colors.orange[300],
                    ),
                    Positioned(
                      top: 10,
                      left: 10,
                      child: Icon(Icons.shopping_cart,
                          size: 40, color: Colors.white),
                    ),
                    Positioned(
                      bottom: 10,
                      right: 10,
                      child: Text('Stacked!',
                          style: TextStyle(fontSize: 18, color: Colors.black)),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
