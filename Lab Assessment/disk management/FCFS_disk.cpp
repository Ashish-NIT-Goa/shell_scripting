
#include <bits/stdc++.h>
using namespace std;

// i've assumed total number of cylinders traversed ~ seek time;

int main() {
    int numOfCylinders; 
    int numOfRequests;
    int initHeadPos;

    cout << "Number of cylinders: ";
    cin >> numOfCylinders;
    cout << "Number of requests: ";
    cin >> numOfRequests;
    cout << "Initial head position: ";
    cin >> initHeadPos;


    int seekTime = 0;
    
    vector <int> requests(numOfRequests);
    
    for (int i = 0; i < numOfRequests; i++) {
        cout << "Enter cylinder position for request " << i + 1 << " : ";
        cin >> requests[i];
        seekTime += abs(requests[i] - initHeadPos);
        initHeadPos = requests[i];
    }

    cout << "Seek Time = " << seekTime << "\n";

    return 0;
}