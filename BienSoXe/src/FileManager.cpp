#include "../include/FileManager.h"

map<string, string> provinces;
map<string, string> wards;

void loadData() {

    provinces["01"] = "Ha Noi";
    provinces["02"] = "Ha Giang";
    provinces["04"] = "Cao Bang";
    provinces["08"] = "Tuyen Quang";
    provinces["19"] = "Thai Nguyen";
    provinces["30"] = "Hai Phong";
    provinces["31"] = "Da Nang";
    provinces["48"] = "Dak Lak";
    provinces["50"] = "TP Ho Chi Minh";
    provinces["52"] = "Binh Duong";
    provinces["60"] = "Dong Nai";
    provinces["79"] = "Khanh Hoa";

    wards["01-01"] = "Ba Dinh";
    wards["01-02"] = "Hoan Kiem";
    wards["01-03"] = "Dong Da";

    wards["02-01"] = "Thanh Pho Ha Giang";
    wards["02-02"] = "Dong van";
    wards["02-03"] = "Meo Vac";

    wards["50-01"] = "Quan 1";
    wards["50-02"] = "Quan 2";
    wards["50-03"] = "Quan 3";

    wards["79-01"] = "Nha Trang";
    wards["79-02"] = "Cam Lam";

    wards["52-01"] = "Thu Dau Mot";
    wards["52-02"] = "Di An";

    wards["60-01"] = "Bien Hoa";
    wards["60-02"] = "Long Thanh";
}
