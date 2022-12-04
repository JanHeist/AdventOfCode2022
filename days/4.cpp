#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string splitStr(string data, char splitter, bool secondHalf) {
    stringstream ss(data);
    getline(ss, data, splitter);

    if (!secondHalf)
        return data;

    getline(ss, data, '\n');
    return data;
}

int main() {
    string line;
    ifstream file ("input/4.txt");
    int counter = 0, counter2 = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Aufgabe 1
            string firstHalf = splitStr(line, ',', false);
            string secondHalf = splitStr(line, ',', true);
            int elves[4] = {
                stoi(splitStr(firstHalf, '-', false)),
                stoi(splitStr(firstHalf, '-', true)),
                stoi(splitStr(secondHalf, '-', false)),
                stoi(splitStr(secondHalf, '-', true)),
            };

            if ((elves[0] <= elves[2] && elves[1] >= elves[3]) || (elves[2] <= elves[0] && elves[3] >= elves[1]))
                counter++;

            // Aufgabe 2
            if ((elves[0] >= elves[2] && elves[0] <= elves[3]) || (elves[0] <= elves[2] && elves[1] >= elves[2]))
                counter2 += 1;

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";

    cout << "Counter 1: " << counter << endl;
    cout << "Counter 2: " << counter2 << endl;

    return 0;
}
