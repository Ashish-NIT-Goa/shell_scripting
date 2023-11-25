#include <bits/stdc++.h>

// i've assumed total number of cylinders traversed ~ seek time;

using namespace std;

int main() {

    int numOfCylinders; 
    int numOfRequests;
    int initialHeadPosition;
    cout << "Enter total number of cylinders: ";
    cout << "Enter number of requests: ";
    cout << "Enter initial head position: ";
    cin >> numOfCylinders; 
    cin >> numOfRequests; 
    cin >> initialHeadPosition;

    int seekTime = 0;
    set <int> requests = {98, 183, 37, 122, 14, 124, 65, 67};

    int head = initialHeadPosition;
    int dist = 0;

    int maxi = *max_element(requests.begin(), requests.end());
    int mini = *min_element(requests.begin(), requests.end());

    while (!requests.empty()) {

        if (requests.find(head) != requests.end()) { // found a request
            seekTime += dist;
            dist = 0;
            requests.erase(head);
        }

        if (head == maxi) {
            dist += maxi - mini;
            head = mini;
            continue;
        }

        head++;

        dist++;
    }
    
    cout << "seek time : " << seekTime << "\n";

    return 0;
}

// 98 183 37 122 14 124 65 67