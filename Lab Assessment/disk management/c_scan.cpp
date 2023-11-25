#include <bits/stdc++.h>

// i've assumed total number of cylinders traversed ~ seek time;

using namespace std;

int main()
{
    int numOfCylinders;
    int numOfRequests;
    int initHeadPos;
    cout << "Enter total number of cylinders: "; 
    cout << "Enter number of requests: ";
    cout << "Enter initial head position: ";
    cin >> numOfCylinders; 
    cin >> numOfRequests;
    cin >> initHeadPos;

    int seekTime = 0;
    set<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};

    int head = initHeadPos;

    int dist = 0;

    while (!requests.empty()) {

        if (head == numOfCylinders - 1) {
            dist += 200;
            head = 0;
        }

        if (requests.find(head) != requests.end()) { // found a request
            seekTime += dist;
            dist = 0;
            requests.erase(head);
        }

        head++;

        dist++;
    }
    cout << "seek time : " << seekTime << "\n";

    return 0;
}

// 98 183 37 122 14 124 65 67