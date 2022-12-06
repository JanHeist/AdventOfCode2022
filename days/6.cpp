#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool checkArr(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (i != j && arr[i] == arr[j])
                return false;
        }
    }
    return true;
}

int main() {
    string line;
    ifstream file ("input/6.txt");
    int task1, task2;

    if (file.is_open()) {
        while (getline(file, line)) {

            int arr[4], arr2[14];
            bool arr1Check = true, arr2Check = true;

            for (int i = 0; i < line.length(); i++) {
                arr[i%4] = line[i]; // 1st Task
                arr2[i%14] = line[i]; // 2nd Task

                if (arr1Check && i >= 4 && checkArr(arr, 4)) {
                    task1 = i+1;
                    arr1Check = false;
                }

                if (arr2Check && i >= 14 && checkArr(arr2, 14)) {
                    task2 = i+1;
                    arr2Check = false;
                }

                if (!arr1Check && !arr2Check)
                    break;
            }

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";

    cout << "Task 1: " << task1 << endl;
    cout << "Task 2: " << task2 << endl;

    return 0;
}
