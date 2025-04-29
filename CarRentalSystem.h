#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include "Vehicle.h"
#include "Booking.h"
#include "Customer.h"
#include "Admin.h"

class CarRentalSystem {
private:
    Vehicle* vehicles[10];
    int vCount;
    Customer customers[5];
    int cCount;
    Admin admin;
    Customer* loggedInCustomer;
public:
    CarRentalSystem();
    ~CarRentalSystem();
    void addVehicle(Vehicle* v);
    void showVehicles();
    void registerCustomer();
    bool customerLogin();
    bool adminLogin();
    void customerMenu();
    void adminMenu();
    void mainMenu();
};

#endif
