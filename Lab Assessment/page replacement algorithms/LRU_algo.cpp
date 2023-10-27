#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int capacity, page_faults = 0;
    cin >> capacity;

    unordered_map<int, bool> in_memory;
    queue<int> page_queue;

    int page;
    while (cin >> page) {
        if (in_memory[page]) {
            // Page is already in memory
            // Move it to the back of the queue
            while (page_queue.front() != page) {
                int front_page = page_queue.front();
                page_queue.pop();
                page_queue.push(front_page);
            }
        } else {
            // Page is not in memory
            if (page_queue.size() == capacity) {
                // Evict the least recently used page
                int lru_page = page_queue.front();
                page_queue.pop();
                in_memory[lru_page] = false;
            }
            // Add the new page to memory
            page_queue.push(page);
            in_memory[page] = true;
            page_faults++;
        }
    }

    cout << "Total page faults: " << page_faults << endl;

    return 0;
}