#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"

class Admin : public Person {
public:
    Admin(string n = "", string u = "", string p = "");
    void showProfile() override;
};

#endif
