#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    string brand, model;
    double pricePerDay;
    bool available;
public:
    Vehicle(string b = "", string m = "", double price = 0);
    virtual void displayInfo();
    bool isAvailable();
    void rentOut();
    void returnBack();
    string getDetails();
    double getPrice();
};

class Sedan : public Vehicle {
public:
    Sedan(string b, string m, double price);
    void displayInfo() override;
};

class SUV : public Vehicle {
public:
    SUV(string b, string m, double price);
    void displayInfo() override;
};

class Truck : public Vehicle {
public:
    Truck(string b, string m, double price);
    void displayInfo() override;
};

#endif
