#include <iostream>
#include <string>
#include <map>

#include "../include/LinkedList.h"
#include "../include/HashTable.h"
#include "../include/FileManager.h"
#include "../include/LicensePlate.h"

using namespace std;

extern map<string, string> provinces;
extern map<string, string> wards;


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

    loadFromTxt("provinceCode.txt");
    loadFromTxt("wardCode.txt");


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
            list.insert(lp);
            table.insert(plate);

            cout << "Dang ky thanh cong!\n";
            break;
        }

        case 2: {
            string plate;
            cout << "Nhap bien so can tra cuu: ";
            getline(cin, plate);

            if (!table.search(plate)) {
                cout << "Khong tim thay bien so!\n";
                break;
            }

            LicensePlate* result = list.search(plate);
            if (result == nullptr) {
                cout << "Khong co thong tin chi tiet!\n";
                break;
            }

            string provinceCode = plate.substr(0, 2);
            string wardCode = plate.substr(0, 5);

            cout << "\n=== THONG TIN BIEN SO ===\n";
            result->display();
            cout << "Tinh: " << provinces[provinceCode] << endl;
            cout << "Xa  : " << wards[wardCode] << endl;
            break;
        }

        case 3: {
            string province;
            cout << "Nhap ma Tinh (ab): ";
            getline(cin, province);

            cout << "Danh sach ma Xa cua Tinh " << province << ":\n";

            for (auto& w : wards) {
                if (w.first.substr(0, 2) == province) {
                    cout << w.first.substr(3, 2) << " - " << w.second << endl;
                }
            }
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
