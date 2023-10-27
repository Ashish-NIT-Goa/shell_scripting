
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
    cout << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfPartitions; j++) {
            if (processSize[i] <= partitionSize[j]) {
                partitionSize[j] = partitionSize[j] - processSize[i];
                cout << "process " << i << " went into " << "partition " << j << endl;
                break;
            }
        }
    }
    
    cout << endl << "Final partition..." << endl;

    for (int i = 0; i < numberOfPartitions; i++) {
        cout << partitionSize[i] << " ";
    }

    return 0;
}

