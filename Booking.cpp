#include "Booking.h"

Booking::Booking(Vehicle* v, int d) : vehicle(v), days(d) {}

double Booking::calculateTotal() {
    if (vehicle != nullptr)
        return vehicle->getPrice() * days;
    else return 0;
}
