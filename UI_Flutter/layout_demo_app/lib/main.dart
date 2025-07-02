import 'package:flutter/material.dart';

void main() {
  runApp(const LayoutDemoApp());
}

class LayoutDemoApp extends StatelessWidget {
  const LayoutDemoApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Layout Demo',
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Row, Column & Stack Demo'),
        ),
        body: SingleChildScrollView(
          child: Padding(
            padding: const EdgeInsets.all(16),
            child: Column(
              children: [
                //column demo
                const Text(
                  'Column Layout',
                  style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                ),
                Container(
                  color: Colors.blue[50],
                  padding: const EdgeInsets.all(8),
                  child: Column(
                    children: const [
                      Text('Item 1'),
                      SizedBox(height: 8),
                      Text('Item 2'),
                      SizedBox(height: 8),
                      Text('Item 3'),
                    ],
                  ),
                ),

                const SizedBox(height: 24),

                // row demo
                const Text(
                  'Row Layout',
                  style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                ),
                Container(
                  color: Colors.green[50],
                  padding: const EdgeInsets.all(8),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: const [
                      Icon(Icons.star, color: Colors.orange, size: 30),
                      Icon(Icons.favorite, color: Colors.red, size: 30),
                      Icon(Icons.thumb_up, color: Colors.blue, size: 30),
                    ],
                  ),
                ),

                const SizedBox(height: 24),

                // stack demo
                const Text(
                  'Stack Layout',
                  style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                ),
                Container(
                  width: 200,
                  height: 200,
                  color: Colors.grey[300],
                  child: Stack(
                    children: [
                      Container(
                        width: 200,
                        height: 200,
                        color: Colors.yellow,
                      ),
                      Positioned(
                        top: 30,
                        left: 30,
                        child: Container(
                          width: 100,
                          height: 100,
                          color: Colors.blue,
                        ),
                      ),
                      Positioned(
                        bottom: 10,
                        right: 10,
                        child: const Text(
                          'Stacked Text',
                          style: TextStyle(
                            color: Colors.white,
                            backgroundColor: Colors.black,
                          ),
                        ),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
