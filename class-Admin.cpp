#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string n, string u, string p) : Person(n, u, p) {}

void Admin::showProfile() {
    cout << "Admin Name: " << name << endl;
}
