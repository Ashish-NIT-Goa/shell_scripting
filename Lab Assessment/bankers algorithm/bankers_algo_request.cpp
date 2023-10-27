#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_PROCESS = 10;
const int MAX_RESOURCE = 10;

int available[MAX_RESOURCE];
int allocation[MAX_PROCESS][MAX_RESOURCE];
int max_need[MAX_PROCESS][MAX_RESOURCE];
int need[MAX_PROCESS][MAX_RESOURCE];
bool finished[MAX_PROCESS];

vector<int> safety_sequence;

bool is_safe() {
    int n = safety_sequence.size();
    vector<bool> visited(n, false);
    vector<int> work(available, available + MAX_RESOURCE);

    for (int i = 0; i < n; i++) {
        int p = safety_sequence[i];
        if (!visited[p]) {
            bool can_finish = true;
            for (int j = 0; j < MAX_RESOURCE; j++) {
                if (need[p][j] > work[j]) {
                    can_finish = false;
                    break;
                }
            }
            if (can_finish) {
                visited[p] = true;
                for (int j = 0; j < MAX_RESOURCE; j++) {
                    work[j] += allocation[p][j];
                }
                i = -1;
            }
        }
    }

    return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

void print_safety_sequence() {
    cout << "Safety sequence: ";
    for (int i = 0; i < safety_sequence.size(); i++) {
        cout << "P" << safety_sequence[i];
        if (i != safety_sequence.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    cout << "Enter available resources: ";
    for (int i = 0; i < m; i++) {
        cin >> available[i];
    }

    cout << "Enter allocation matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter max need matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max_need[i][j];
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    int request_process;
    cout << "Enter process requesting resources: ";
    cin >> request_process;

    int request[MAX_RESOURCE];
    cout << "Enter resource request: ";
    for (int i = 0; i < m; i++) {
        cin >> request[i];
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > need[request_process][i]) {
            cout << "Error: Requested resources exceed maximum need." << endl;
            return 1;
        }
        if (request[i] > available[i]) {
            cout << "Process must wait. Not enough resources available." << endl;
            return 1;
        }
    }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[request_process][i] += request[i];
        need[request_process][i] -= request[i];
    }

    for (int i = 0; i < n; i++) {
        if (!finished[i]) {
            bool can_finish = true;
            for (int j = 0; j < m; j++) {
                if (need[i][j] > available[j]) {
                    can_finish = false;
                    break;
                }
            }
            if (can_finish) {
                finished[i] = true;
                safety_sequence.push_back(i);
                for (int j = 0; j < m; j++) {
                    available[j] += allocation[i][j];
                }
                i = -1;
            }
        }
    }

    if (is_safe()) {
        cout << "Request granted." << endl;
        print_safety_sequence();
    } else {
        cout << "Request denied. System would be unsafe." << endl;
    }

    return 0;
}
