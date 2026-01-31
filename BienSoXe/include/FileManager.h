#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <map>
#include <string>

using namespace std;

extern map<string, string> provinces;
extern map<string, string> wards;

void loadFromTxt(const string& filename);

#endif
