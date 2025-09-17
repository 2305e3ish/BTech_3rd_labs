
// Selective Repeat ARQ (Beginner Level)
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int total_frames, window_size;
    cout << "Selective Repeat ARQ Simulation (Simple)\n";
    cout << "Enter total number of frames: ";
    cin >> total_frames;
    cout << "Enter window size: ";
    cin >> window_size;
    vector<bool> acked(total_frames, false);
    int base = 0, next_seq = 0;
    while (base < total_frames) {
        for (int i = 0; i < window_size && next_seq < total_frames; ++i) {
            cout << "Sent frame: " << next_seq << endl;
            next_seq++;
        }
        for (int i = base; i < base + window_size && i < total_frames; ++i) {
            if (!acked[i]) {
                cout << "ACK received for frame: " << i << endl;
                acked[i] = true;
            }
        }
        while (base < total_frames && acked[base]) base++;
    }
    cout << "All frames sent and acknowledged." << endl;
    return 0;
}

/*
-----------------------------
Selective Repeat ARQ: Explanation & Dry Run
-----------------------------

Definition & Basics:
- Selective Repeat ARQ is an error control protocol for reliable data transmission.
- The sender can send multiple frames (up to the window size) before needing an ACK.
- Each frame is acknowledged individually. Only unacknowledged frames are retransmitted.
- The receiver can accept frames out of order and buffer them until missing frames arrive.

Code Logic:
1. The sender has a total of 8 frames to send, with a window size of 4.
2. The sender sends all frames in the current window (from 'base' to 'base + WINDOW_SIZE - 1').
3. For each frame sent, the code simulates receiving an ACK (in this simple version, all are received immediately).
4. The sender slides the window forward past all consecutively acknowledged frames.
5. The process repeats until all frames are sent and acknowledged.

Sample Dry Run:

Sample Input:
Enter total number of frames: 7
Enter window size: 3

Sample Output:
Selective Repeat ARQ Simulation (Simple)
Enter total number of frames: 7
Enter window size: 3
Sent frame: 0
Sent frame: 1
Sent frame: 2
ACK received for frame: 0
ACK received for frame: 1
ACK received for frame: 2
Sent frame: 3
Sent frame: 4
Sent frame: 5
ACK received for frame: 3
ACK received for frame: 4
ACK received for frame: 5
Sent frame: 6
ACK received for frame: 6
All frames sent and acknowledged.


Output:
All frames sent and acknowledged.

Summary:
Selective Repeat ARQ allows efficient and reliable transmission by only retransmitting frames that are lost or corrupted, not the entire window. This simulation assumes all frames and ACKs are received correctly for simplicity.
*/
