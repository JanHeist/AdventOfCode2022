#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    string line;
    ifstream file ("input/5.txt");

    int rows = 0;
    int cols = 0;
    string lineArr[1000];


    if (file.is_open()) {
        int c = 0;
        bool countrows = true;


        while (getline(file, line)) {

            lineArr[c++] = line;

            cout << ":" << line << ":" << endl;

            cout << line.length() / 4 + 1<< endl;
            if (line.length() / 4 + 1 > cols)
                cols = line.length() / 4 + 1;

            if (countrows && line[1] != '1')
                rows++;
            else if (line[1] == '1')
                countrows = false;

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";


    int data[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;
        }
    }

    cout << "-------" << endl;

    for (int i = rows-1; i >= 0; i--) {
        //cout << lineArr[i] << endl;
        for (int j = 0; j < cols; j++) {
            string tmp = lineArr[i];
            if (j*4+1 > tmp.length())
                break;
            cout << ":tmp:" << tmp << ":" <<  tmp[j*4+1] << ":" << endl;
            for (int k = 0; k < cols; k++) {
                if (data[j][k] == 0 && tmp[j*4+1] != ' ') {
                    data[j][k] = (int) tmp[j*4+1];
                    break;
                }
            }
        }
        cout << " - " << endl;
    }



    cout << "***********" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << (char) data[i][j] << " ";
        }
        cout << endl;
    }



    cout << "ROw; " << rows << endl;

    return 0;
}
