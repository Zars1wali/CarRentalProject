#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class Customer : public Person {
private:
    string bookingHistory[10];
    string feedbackHistory[10];
    int bookingCount;
    int feedbackCount;
public:
    Customer(string n = "", string u = "", string p = "");
    void addBooking(string booking);
    void viewBookings();
    void submitFeedback(string fb);
    void viewFeedbacks();
    void showProfile() override;
};

#endif
