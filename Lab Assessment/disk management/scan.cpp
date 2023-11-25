
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main () {

    int initialHeadPosition;
    cout << "Enter initial head postion: ";
    cin >> initialHeadPosition;

    int numberOfCylinders;
    cout << "Enter number of cylinders: ";
    cin >> numberOfCylinders;

    int numberOfRequests;
    cout << "Enter number of requests: ";
    cin >> numberOfRequests;

    set <int> requests;
    for (int i = 0; i < numberOfRequests; i++) {
        int request;
        cin >> request;
        requests.insert(request);
    }

    int seekTime;

    // SCAN logic
    bool flag = false;
    int head = initialHeadPosition;
    int min_distance = 0;
    while (!requests.empty()) {
        if (head == 0) {
            flag = true;
        } else if (head == numberOfCylinders - 1) {
            flag = false;
        }

        if (requests.find(head) != requests.end()) { // found a request
            seekTime += min_distance;
            min_distance = 0;
            requests.erase(head);
        }

        if (flag == false) {
            head--;
        }

        else
            head++;

        min_distance++;
    }
    cout << "seek time : " << seekTime << "\n";


    return  0;
}