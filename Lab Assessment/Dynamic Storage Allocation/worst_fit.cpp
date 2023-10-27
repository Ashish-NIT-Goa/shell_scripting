
# include <iostream>
using namespace std;

# include <string>

# define MEMORY_SIZE 100

int main() {

    int *arr;

    int numberOfPartitions;
    int numberOfProcesses;

    cout << "Enter number of partitions: ";
    cin >> numberOfPartitions;

    cout << endl << "Enter number of processes: ";
    cin >> numberOfProcesses;

    cout << "Number of partitions: " << numberOfPartitions << endl;
    cout << "Number of processes: " << numberOfProcesses << endl;

    int partitionSize[numberOfPartitions];
    for (int i = 0; i < numberOfPartitions; i++) {
        cout << "Enter the size of partion " << i + 1 << ": " << endl;
        cin >> partitionSize[i];
    }


    int processSize[numberOfProcesses];
    for (int i = 0; i < numberOfProcesses; i++) {
        cout << "Enter the required size of process " << i + 1 << ": " << endl;
        cin >> processSize[i];
    }

    cout << "Initial partition..." << endl;
    for (int i = 0; i < numberOfPartitions; i++) {
        cout << partitionSize[i] << " ";
    }

    // First Fit
    /*
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfPartitions; j++) {
            if (processSize[i] <= partitionSize[j]) {
                partitionSize[j] = partitionSize[j] - processSize[i];
                cout << "process " << i << " went into " << "partition " << j << endl;
                break;
            }
        }
    }
    */

    // Best Fit
    /*
    for (int i = 0; i < numberOfProcesses; i++) {
        int flag = 0;
        int minimum = INT32_MAX;
        int index;
        for (int j = 0; j < numberOfPartitions; j++) {
            if (partitionSize[j] >= processSize[i] && partitionSize[j] < minimum) {
                flag = 1;
                minimum = partitionSize[j];
                index = j;
            }
        }

        if (flag) {
            partitionSize[index] = partitionSize[index] - processSize[i];
            cout << "process " << i << " went into block " << index << endl;
        }
    }
    */

    // Worst Fit
    cout << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        int flag = 0;
        int maximum = INT32_MIN;
        int index;
        for (int j = 0; j < numberOfPartitions; j++) {
            if (partitionSize[j] >= processSize[i] && partitionSize[j] > maximum) {
                flag = 1;
                maximum = partitionSize[j];
                index = j;
            }
        }

        if (flag) {
            partitionSize[index] = partitionSize[index] - processSize[i];
            cout << "process " << i << " went into block " << index << endl;
        } else {
            cout << "process " << i << " could not be allocated" << endl;
        }
    }

    cout << endl << "Final partition..." << endl;

    for (int i = 0; i < numberOfPartitions; i++) {
        cout << partitionSize[i] << " ";
    }

    return 0;
}