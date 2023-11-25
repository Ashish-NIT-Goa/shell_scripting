#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

bool compareByRemainingTime(const Process& p1, const Process& p2) {
    return p1.remainingTime < p2.remainingTime;
}

void shortestTimeRemainingFirst(std::vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;

    while (true) {
        bool allProcessesCompleted = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                allProcessesCompleted = false;

                if (processes[i].arrivalTime <= currentTime) {
                    processes[i].remainingTime--;

                    if (processes[i].remainingTime == 0) {
                        std::cout << "Process " << processes[i].id << " completed at time " << currentTime + 1 << std::endl;
                    }
                }
            }
        }

        if (allProcessesCompleted) {
            break;
        }

        currentTime++;
    }
}

int main() {
    std::vector<Process> processes = {
        {1, 0, 6, 6},
        {2, 2, 4, 4},
        {3, 4, 2, 2},
        {4, 6, 8, 8},
        {5, 8, 10, 10}
    };

    std::sort(processes.begin(), processes.end(), compareByRemainingTime);

    shortestTimeRemainingFirst(processes);

    return 0;
}
