#include <iostream>
#include <string>
#include <sstream>
#include "../utils/getinput.hpp"
using namespace std;

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

    if (!second)
        return charToCustomInt(data);
    else {
        getline(ss, data, '\n');
        return charToCustomInt(data);
    }

}

class combination {
public:
    int x, y, value;
    combination(int x, int y, int value) {
        this->x = x;
        this->y = y;
        this->value = value;
    }
};

combination combinations[9] = {
        *new combination(1, 3, 0 + 3),
        *new combination(1, 1, 3 + 1),
        *new combination(1, 2, 6 + 2),
        *new combination(2, 3, 6 + 3),
        *new combination(2, 1, 0 + 1),
        *new combination(2, 2, 3 + 2),
        *new combination(3, 3, 3 + 3),
        *new combination(3, 1, 6 + 1),
        *new combination(3, 2, 0 + 2)
};

int getCombinationValue(int x, int y) {
    for (int i = 0; i < 9; i++) {
        if(combinations[i].x == x && combinations[i].y == y)
            return combinations[i].value;
    }
    return 0;
}

int main() {
    string line;
    ifstream file ("input/2.txt");

    int count = 0;

    if (file.is_open()) {
        while (getline(file, line)) {

            count += getCombinationValue(getNumFromString(line, false), getNumFromString(line, true));


        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";

    cout << "Punkte: " << count;

    return 0;
}
