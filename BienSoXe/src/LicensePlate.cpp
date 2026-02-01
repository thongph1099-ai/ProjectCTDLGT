#include "LicensePlate.h"

LicensePlate::LicensePlate() {
    id = "";
    owner_name = "";
    driver_type = "";
    next = nullptr;
}

LicensePlate::LicensePlate(string id, string owner, string type) {
    this->id = id;
    this->owner_name = owner;
    this->driver_type =type;
    next = nullptr;
}

void LicensePlate::display() {
    cout << "ID: " << id << endl;
    cout << "Chu xe: " << owner_name << endl;
    cout << "Loai xe: " << driver_type << endl;
    cout << "---------------------------" << endl;
}

