#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    string line;
    ifstream file ("input/3.txt");

    if (file.is_open()) {
        while (getline(file, line)) {

            cout << line << endl;

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";


    return 0;
}
