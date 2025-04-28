#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name, username, password;
public:
    Person(string n = "", string u = "", string p = "");
    virtual void showProfile() = 0;
    string getUsername();
    string getPassword();
};

#endif
