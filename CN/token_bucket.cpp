// Token Bucket Algorithm (Simple, Manual Style)
#include <iostream>
using namespace std;

int main() {
    int bucket_size, n, pkt_size, tokens = 0, rate, token_rate;
    cout << "Enter bucket size: ";
    cin >> bucket_size;
    cout << "Enter output rate: ";
    cin >> rate;
    cout << "Enter token generation rate: ";
    cin >> token_rate;
    cout << "Enter number of packets: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter packet size: ";
        cin >> pkt_size;
        tokens += token_rate;
        if (tokens > bucket_size) tokens = bucket_size;
        if (pkt_size > tokens)
            cout << "Packet dropped\n";
        else {
            cout << "Sent " << pkt_size << " bytes\n";
            tokens -= pkt_size;
        }
    }
    return 0;
}
