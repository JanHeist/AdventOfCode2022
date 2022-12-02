#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int POSSIBLE_COMBINATIONS = 9;

int charToCustomInt(string data) {
    if (data == "A" || data == "X")
        return 1;
    else if (data == "B" || data == "Y")
        return 2;
    else if (data == "C" || data == "Z")
        return 3;
    return 0;
}

int getNumFromString(string data, bool second) {
    stringstream ss(data);
    getline(ss, data, ' ');

    if (!second) // Ersten Teil zurückgeben
        return charToCustomInt(data);

    // Zweiten Teil zurückgeben
    getline(ss, data, '\n');
    return charToCustomInt(data);
}

// Kombinations-Klasse
class CombinationClass {
public:
    int x, y, value;
    CombinationClass(int x, int y, int value) {
        this->x = x;
        this->y = y;
        this->value = value;
    }
};

// Verfügbare Kombinationen mit Punkten
CombinationClass combinations[POSSIBLE_COMBINATIONS] = {
        *new CombinationClass(1, 3, 0 + 3),
        *new CombinationClass(1, 1, 3 + 1),
        *new CombinationClass(1, 2, 6 + 2),
        *new CombinationClass(2, 3, 6 + 3),
        *new CombinationClass(2, 1, 0 + 1),
        *new CombinationClass(2, 2, 3 + 2),
        *new CombinationClass(3, 3, 3 + 3),
        *new CombinationClass(3, 1, 6 + 1),
        *new CombinationClass(3, 2, 0 + 2)
};

int getCombinationValue(int x, int y) {
    for (int i = 0; i < POSSIBLE_COMBINATIONS; i++) {
        if(combinations[i].x == x && combinations[i].y == y)
            return combinations[i].value;
    }
    return 0;
}


int main() {
    string line;
    ifstream file ("input/2.txt");

    int count = 0, count2 = 0;

    if (file.is_open()) {
        while (getline(file, line)) {

            // Aufgabe 1 zusammenrechnen
            count += getCombinationValue(getNumFromString(line, false), getNumFromString(line, true));

            // Aufgabe 2
            int first = getNumFromString(line, false);
            int second = getNumFromString(line, true);

            if (second == 1) { // verlieren
                if (first == 1)
                    second = 3;
                else if (first == 3)
                    second = 2;
            } else if (second == 2) { // gleichstand
                second = first;
            } else if (second == 3) { // gewinnen
                if (first == 1)
                    second = 2;
                else if (first == 3)
                    second = 1;
            }

            count2 += getCombinationValue(first, second);

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";

    cout << "Punkte 1: " << count << endl;
    cout << "Punkte 2: " << count2 << endl;

    return 0;
}
