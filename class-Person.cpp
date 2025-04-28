#include "Person.h"

Person::Person(string n, string u, string p) : name(n), username(u), password(p) {}

string Person::getUsername() {
    return username;
}

string Person::getPassword() {
    return password;
}
