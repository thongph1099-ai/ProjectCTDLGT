#ifndef LICENSE_PLATE_H
#define LICENSE_PLATE_H

#include <iostream>
#include <string>

using namespace std;

struct LicensePlate {
    string id;
    string owner_name;
    string driver_type;

    LicensePlate* next;

    LicensePlate();
    LicensePlate(string id, string owner, string type);
    void display();
};


#endif  
