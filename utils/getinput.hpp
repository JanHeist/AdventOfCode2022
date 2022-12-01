#include <iostream>
#include <fstream>
using namespace std;

string getInput(string filename) {
    string input;

    string line;
    ifstream file ("input/" + filename + ".txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            input += "\n" + line;
        }
        file.close();
    } else {
        cout << "Konnte Datei nicht oeffnen";
    }

    return input;
}
