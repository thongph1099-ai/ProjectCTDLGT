#ifndef LICENSE_PLATE_H
#define LICENSE_PLATE_H

#include <iostream>
#include <string>

using namespace std;

struct LicensePlate {
    string id;
    string provinceCode;
    string wardCode;

    LicensePlate* next;

    LicensePlate();
    LicensePlate(string id, string province, string ward);
    void display();
};


#endif  
