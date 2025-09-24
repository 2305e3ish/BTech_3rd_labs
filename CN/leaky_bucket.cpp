// Leaky Bucket Algorithm (Manual Style, All in main, Clean Output)
#include <iostream>
#include <cstdlib>
using namespace std;
#define bucketSize 512

int main() {
    int op, pktSize;
    cout << "Enter output rate : ";
    cin >> op;
    for(int i = 0; i < 5; i++) {
        pktSize = rand() % 1000;
        cout << "\nPacket no " << i << ", Packet size = " << pktSize << endl;
        if(pktSize > bucketSize)
            cout << "Bucket overflow" << endl;
        else {
            int a = pktSize;
            while(a > op) {
                cout << op << " bytes outputted." << endl;
                a -= op;
            }
            if(a > 0) cout << "Last " << a << " bytes sent" << endl;
            cout << "Bucket output successful" << endl;
        }
    }
    return 0;
}
