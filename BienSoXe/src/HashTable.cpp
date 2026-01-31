#include "../include/HashTable.h"
#include <iostream>
#include <fstream>

using namespace std;

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        LicenseNode* curr = table[i];
        while (curr != nullptr) {
            LicenseNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}

int HashTable::hashFunction(const string& province, const string& ward) {
    int key = stoi(province + ward);
    return key % TABLE_SIZE;
}

void HashTable::insert(const string& license) {
    string province = license.substr(0, 2);
    string ward = license.substr(3, 2);

    int index = hashFunction(province, ward);

    LicenseNode* newNode = new LicenseNode;
    newNode->license = license;
    newNode->province = province;
    newNode->ward = ward;
    newNode->next = table[index];

    table[index] = newNode;
}

bool HashTable::search(const string& license) {
    string province = license.substr(0, 2);
    string ward = license.substr(3, 2);

    int index = hashFunction(province, ward);
    LicenseNode* curr = table[index];

    while (curr != nullptr) {
        if (curr->license == license) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void HashTable::displayWardsByProvince(const string& province) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        LicenseNode* curr = table[i];
        while (curr != nullptr) {
            if (curr->province == province) {
                cout << curr->ward << endl;
            }
            curr = curr->next;
        }
    }
}

void HashTable::displayLicensesByWard(const string& province, const string& ward) {
    int index = hashFunction(province, ward);
    LicenseNode* curr = table[index];

    while (curr != nullptr) {
        if (curr->province == province && curr->ward == ward) {
            cout << curr->license << endl;
        }
        curr = curr->next;
    }
}

void HashTable::loadProvinceFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        int pos = line.find(",");
        string code = line.substr(0, pos);
        string name = line.substr(pos + 1);

        provinces[code] = name;
    }
    file.close();
}

void HashTable::loadWardFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        int pos = line.find(",");
        string code = line.substr(0, pos);
        string name = line.substr(pos + 1);

        wards[code] = name;
    }
    file.close();
}

string HashTable::getProvinceName(const string& code) {
    if (provinces.count(code)) return provinces[code];
    return "";
}

string HashTable::getWardName(const string& code) {
    if (wards.count(code)) return wards[code];
    return "";
}
