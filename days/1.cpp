#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int arr_size = 1;
int* arr = new int[arr_size] {0};

void needBiggerArray() {
    size_t newSize = arr_size + 1;
    int* newArr = new int[newSize];

    memcpy( newArr, arr, arr_size * sizeof(int) );

    arr_size = newSize;
    delete [] arr;
    arr = newArr;
    arr[newSize-1] = 0;
}

int main() {

    string line;
    ifstream file ("input/1.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "\n" || line.length() == 0)
                needBiggerArray();
            else arr[arr_size-1] += stoi(line);
        }
        file.close();
    } else
        cout << "Konnte Datei nicht oeffnen";

    int top1 = 0, top2 = 0, top3 = 0;
    for (int i = 0; i < arr_size; i++) {
        cout << "Elf " << i + 1 << ": " << arr[i] << endl;
        if (arr[i] > top1) {
            top3 = top2;
            top2 = top1;
            top1 = arr[i];
        } else if (arr[i] > top2) {
            top3 = top2;
            top2 = arr[i];
        } else if (arr[i] > top3)
            top3 = arr[i];
    }

    cout << endl << "Top1: " << top1;
    cout << endl << "Top2: " << top2;
    cout << endl << "Top3: " << top3;

    cout << endl << endl << "Top1-3: " << top1 + top2 + top3;

    return 0;
}
