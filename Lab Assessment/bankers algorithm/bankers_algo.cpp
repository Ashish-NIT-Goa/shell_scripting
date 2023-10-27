#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_PROCESS = 100;
const int MAX_RESOURCE = 100;

int n, m; // n = number of processes, m = number of resources
int available[MAX_RESOURCE];
int allocation[MAX_PROCESS][MAX_RESOURCE];
int max_need[MAX_PROCESS][MAX_RESOURCE];
int need[MAX_PROCESS][MAX_RESOURCE];
bool finish[MAX_PROCESS];

vector<int> safe_sequence;

void print_safe_sequence() {
    cout << "Safe sequence: ";
    for (int i = 0; i < safe_sequence.size(); i++) {
        cout << "P" << safe_sequence[i];
        if (i != safe_sequence.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

bool is_safe() {
    // Initialize finish array to false
    fill(finish, finish + n, false);

    // Initialize work array to available
    int work[MAX_RESOURCE];
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    // Find an i such that both:
    // 1. finish[i] == false
    // 2. need[i] <= work
    bool found;
    do {
        found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool need_le_work = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        need_le_work = false;
                        break;
                    }
                }
                if (need_le_work) {
                    // Mark process i as finished
                    finish[i] = true;
                    // Release allocated resources
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    // Add process i to safe sequence
                    safe_sequence.push_back(i);
                    found = true;
                }
            }
        }
    } while (found);

    // Check if all processes are finished
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Input number of processes and resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    // Input available resources
    cout << "Enter available resources: ";
    for (int i = 0; i < m; i++) {
        cin >> available[i];
    }

    // Input allocation matrix
    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    // Input max need matrix
    cout << "Enter max need matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max_need[i][j];
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    // Check if the system is in a safe state
    if (is_safe()) {
        print_safe_sequence();
    } else {
        cout << "System is in an unsafe state\n";
    }

    return 0;
}
