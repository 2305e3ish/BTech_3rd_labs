import 'package:flutter/material.dart';

void main() {
  runApp(const LayoutDemoApp());
}

class LayoutDemoApp extends StatelessWidget {
  const LayoutDemoApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Layout Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatelessWidget {
  const MyHomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Row, Column & Stack Demo'),
        backgroundColor: Colors.blue,
      ),
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              // Column demo
              const Text(
                'Column Layout',
                style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 8),
              Container(
                width: double.infinity,
                color: Colors.blue[50],
                padding: const EdgeInsets.all(16),
                child: const Column(
                  children: [
                    Text('Item 1'),
                    SizedBox(height: 8),
                    Text('Item 2'),
                    SizedBox(height: 8),
                    Text('Item 3'),
                  ],
                ),
              ),

              const SizedBox(height: 24),

              // Row demo
              const Text(
                'Row Layout',
                style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 8),
              Container(
                width: double.infinity,
                color: Colors.green[50],
                padding: const EdgeInsets.all(16),
                child: const Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Icon(Icons.star, color: Colors.orange, size: 30),
                    Icon(Icons.favorite, color: Colors.red, size: 30),
                    Icon(Icons.thumb_up, color: Colors.blue, size: 30),
                  ],
                ),
              ),

              const SizedBox(height: 24),

              // Stack demo
              const Text(
                'Stack Layout',
                style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 8),
              Container(
                width: double.infinity,
                height: 200,
                color: Colors.grey[300],
                child: Stack(
                  children: [
                    Container(
                      width: double.infinity,
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
                    const Positioned(
                      bottom: 10,
                      right: 10,
                      child: Text(
                        'Stacked Text',
                        style: TextStyle(
                          color: Colors.white,
                          backgroundColor: Colors.black,
                          fontSize: 16,
                        ),
                      ),
                    ),
                  ],
                ),
              ),

              const SizedBox(height: 24),

              // Additional examples
              const Text(
                'Advanced Layout Examples',
                style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 8),

              // Expanded example
              Container(
                height: 100,
                color: Colors.purple[50],
                child: const Row(
                  children: [
                    Expanded(
                      flex: 1,
                      child: Container(
                        color: Colors.red,
                        child: Center(
                            child: Text('Flex 1',
                                style: TextStyle(color: Colors.white))),
                      ),
                    ),
                    Expanded(
                      flex: 2,
                      child: Container(
                        color: Colors.green,
                        child: Center(
                            child: Text('Flex 2',
                                style: TextStyle(color: Colors.white))),
                      ),
                    ),
                    Expanded(
                      flex: 1,
                      child: Container(
                        color: Colors.blue,
                        child: Center(
                            child: Text('Flex 1',
                                style: TextStyle(color: Colors.white))),
                      ),
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
