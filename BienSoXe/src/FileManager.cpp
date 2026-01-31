#include "../include/FileManager.h"
#include <fstream>
#include <sstream>

map<string, string> provinces;
map<string, string> wards;

void loadFromTxt(const string& filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) return;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string code, name;

        getline(ss, code, ',');
        getline(ss, name);

        if (code.size() == 2) {
            provinces[code] = name;
        }
        else if (code.size() == 5) {
            wards[code] = name;
        }
    }

    file.close();
}
