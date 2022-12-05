#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string splitStr(string data, char splitter, int index) {
    stringstream ss(data);
    getline(ss, data, splitter);

    for (int i = 0; i <= index-1; i++) {
        getline(ss, data, splitter);
    }

    return data;
}

int gettop(int *arr, int col, int row) {
    for (int i = col*row - 1; i >= 0; i--) {
        if (arr[i] != 0)
            return i;
    }
    return 0;
}

void addtop(int *arr, int col, int row, int data) {
    for (int i = 0; i < col*row; i++) {
        if (arr[i] == 0) {
            arr[i] = data;
            return;
        }
    }
}

int main() {
    string line;
    ifstream file ("input/5.txt");

    int rows = 0, cols = 0;
    string lineArr[512];

    if (file.is_open()) {
        int c = 0;
        bool countrows = true;

        while (getline(file, line)) {
            lineArr[c++] = line;

            if (line.length() / 4 + 1 > cols)
                cols = line.length() / 4 + 1;

            if (countrows && line[1] != '1')
                rows++;
            else if (line[1] == '1')
                countrows = false;
        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";


    int data[cols][cols*rows];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < cols*rows; j++) {
            data[i][j] = 0;
        }
    }


    for (int i = rows-1; i >= 0; i--) {
        for (int j = 0; j < cols; j++) {
            string tmp = lineArr[i];
            if (j*4+1 > tmp.length())
                break;
            for (int k = 0; k < cols; k++) {
                if (data[j][k] == 0 && tmp[j*4+1] != ' ') {
                    data[j][k] = (int) tmp[j*4+1];
                    break;
                }
            }
        }
    }

    file.open("input/5.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line[0] != 'm')
                continue;

            int amount = stoi(splitStr(line, ' ', 1));
            int from = stoi(splitStr(line, ' ', 3));
            int to = stoi(splitStr(line, ' ', 5));

            for (int i = 0; i < amount; i++) {
                int top = gettop(data[from - 1], cols, rows);
                top = top - (amount - i) + 1;
                addtop(data[to - 1], cols, rows, data[from-1][top]);
                data[from - 1][top] = 0;
            }

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";

    string result;
    for (int i = 0; i < cols; i++) {
        result += (char) data[i][gettop(data[i], cols, rows)];
    }
    cout << "Result: " << result << endl;

    return 0;
}
