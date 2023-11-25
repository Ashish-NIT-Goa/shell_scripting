
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, head, total_seek_time = 0;
    vector <int> requests;

    int numberOfRequests;
    cout << "Enter number of requests: ";
    cin >> numberOfRequests;

    cout << "Enter number of cylinders: ";
    cin >> n;
    cout << "Enter requests: ";
    for (int i = 0; i < numberOfRequests; i++) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    cout << "Enter initial head position: ";
    cin >> head;

    // SSTF algorithm
    while (!requests.empty()) {
        int min_distance = abs(requests[0] - head);
        int min_index = 0;
        for (int i = 1; i < requests.size(); i++) {
            int distance = abs(requests[i] - head);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = i;
            }
        }
        total_seek_time += min_distance;
        head = requests[min_index];
        requests.erase(requests.begin() + min_index);
    }

    cout << "Total seek time: " << total_seek_time << endl;

    return 0;
}
