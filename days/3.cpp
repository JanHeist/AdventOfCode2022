#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Aufgabe 1: Duplikat finden
char getDuplicate(char* arr1, char* arr2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr1[i] == arr2[j])
                return arr1[i];
        }
    }
    return '0';
}

// Aufgabe 2: Duplikat finden
char getDuplicate(string s1, string s2, string s3) {
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            for (int k = 0; k < s3.length(); k++) {
                if (s1[i] == s2[j] && s1[i] == s3[k])
                    return s1[i];
            }
        }
    }
    return '0';
}

// Char zu custom Int zum Berechnen
int charToCustomInt(char x) {
    if (x <= 'z' && x >= 'a')
        return (int) x - 96;
    else return (int) x - 38;
}

int main() {
    string line;
    ifstream file ("input/3.txt");

    int counter = 0, counter2 = 0;

    string l1, l2, l3;

    if (file.is_open()) {
        while (getline(file, line)) {

            // Aufgabe 1
            char* arr1 = new char[line.length()/2];
            char* arr2 = new char[line.length()/2];

            for (int i = 0; i < line.length() / 2; i++) {
                arr1[i] = line[i];
                arr2[i] = line[i + line.length()/2];
            }

            counter += charToCustomInt(getDuplicate(arr1, arr2, line.length()/2));

            // Aufgabe 2
            if (l1.empty())
                l1 = line;
            else if (l2.empty())
                l2 = line;
            else if (l3.empty())
                l3 = line;

            if (!l1.empty() && !l2.empty() && !l3.empty()) {
                counter2 += charToCustomInt(getDuplicate(l1, l2, l3));
                l1 = ""; l2 = ""; l3 = "";
            }

        }
        file.close();
    } else cout << "Konnte Datei nicht oeffnen";

    cout << "Punkte 1: " << counter << endl;
    cout << "Punkte 2: " << counter2 << endl;

    return 0;
}
