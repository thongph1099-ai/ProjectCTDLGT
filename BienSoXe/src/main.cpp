#include <iostream>
#include <string>

#include "LinkedList.h"
#include "HashTable.h"

using namespace std;

void menu() {
    cout << "\n===== HE THONG QUAN LY BIEN SO XE =====\n";
    cout << "1. Dang ky bien so moi\n";
    cout << "2. Tra cuu mot bien so\n";
    cout << "3. Hien thi danh sach ma Xa cua mot Tinh\n";
    cout << "4. Hien thi danh sach bien so cua mot Xa\n";
    cout << "5. Hien thi tat ca bien so\n";
    cout << "0. Thoat\n";
    cout << "=====================================\n";
    cout << "Chon: ";
}

int main() {
    LinkedList list;
    HashTable table;

    int choice;
    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string plate, owner, type;

            cout << "Nhap bien so (ab-cd-ghxyz): ";
            getline(cin, plate);

            cout << "Nhap ten chu xe: ";
            getline(cin, owner);

            cout << "Nhap loai xe: ";
            getline(cin, type);

            LicensePlate lp(plate, owner, type);
            list.insert(lp);       // LinkedList luu day du
            table.insert(plate);   // HashTable phuc vu tra cuu

            cout << "Dang ky thanh cong!\n";
            break;
        }

        case 2: {
            string plate;
            cout << "Nhap bien so can tra cuu: ";
            getline(cin, plate);

            if (table.search(plate))
                cout << "Bien so TON TAI trong he thong!\n";
            else
                cout << "Khong tim thay bien so!\n";
            break;
        }

        case 3: {
            string province;
            cout << "Nhap ma Tinh (ab): ";
            getline(cin, province);

            table.displayWardsByProvince(province);
            break;
        }

        case 4: {
            string province, ward;
            cout << "Nhap ma Tinh (ab): ";
            getline(cin, province);

            cout << "Nhap ma Xa (cd): ";
            getline(cin, ward);

            table.displayLicensesByWard(province, ward);
            break;
        }

        case 5:
            list.displayAll();
            break;

        case 0:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
