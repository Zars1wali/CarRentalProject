#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string b, string m, double price) : brand(b), model(m), pricePerDay(price), available(true) {}

void Vehicle::displayInfo() {
    cout << brand << " " << model << " - $" << pricePerDay << "/day " << (available ? "(Available)" : "(Rented)") << endl;
}

bool Vehicle::isAvailable() { return available; }
void Vehicle::rentOut() { available = false; }
void Vehicle::returnBack() { available = true; }
string Vehicle::getDetails() { return brand + " " + model; }
double Vehicle::getPrice() { return pricePerDay; }

Sedan::Sedan(string b, string m, double price) : Vehicle(b, m, price) {}
void Sedan::displayInfo() { cout << "Sedan: "; Vehicle::displayInfo(); }

SUV::SUV(string b, string m, double price) : Vehicle(b, m, price) {}
void SUV::displayInfo() { cout << "SUV: "; Vehicle::displayInfo(); }

Truck::Truck(string b, string m, double price) : Vehicle(b, m, price) {}
void Truck::displayInfo() { cout << "Truck: "; Vehicle::displayInfo(); }
