#include "LicensePlate.h"

LicensePlate::LicensePlate() {
    id = "";
    provinceCode = "";
    wardCode = "";
    next = nullptr;
}

LicensePlate::LicensePlate(string id, string province, string ward) {
    this->id = id;
    this->provinceCode = province;
    this->wardCode = ward;
    next = nullptr;
}

void LicensePlate::display() {
    cout << "ID: " << id << endl;
    cout << "Ma tinh: " << provinceCode << endl;
    cout << "Ma phuong: " << wardCode << endl;
    cout << "---------------------------" << endl;
}

