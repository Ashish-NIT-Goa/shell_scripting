#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int numFrames, numPages;
    cout << "Enter the number of frames: ";
    cin >> numFrames;
    cout << "Enter the number of pages: ";
    cin >> numPages;

    vector<int> pages(numPages);
    cout << "Enter the page reference string: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    unordered_set<int> frameSet;
    queue<int> frameQueue;
    vector<bool> secondChance(numFrames, false);
    int pageFaults = 0;

    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];

        if (frameSet.find(currentPage) == frameSet.end()) {
            while (!frameQueue.empty() && secondChance[frameQueue.front()]) {
                secondChance[frameQueue.front()] = false;
                frameQueue.push(frameQueue.front());
                frameQueue.pop();
            }

            if (!frameQueue.empty()) {
                frameSet.erase(frameQueue.front());
                frameQueue.pop();
            }

            frameSet.insert(currentPage);
            frameQueue.push(currentPage);
            pageFaults++;
        } else {
            secondChance[currentPage] = true;
        }
    }

    cout << "Number of page faults: " << pageFaults << endl;

    return 0;
}
