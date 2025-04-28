#ifndef BOOKING_H
#define BOOKING_H

#include "Vehicle.h"

class Booking {
private:
    Vehicle* vehicle;
    int days;
public:
    Booking(Vehicle* v = nullptr, int d = 0);
    double calculateTotal();
};

#endif
