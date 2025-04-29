#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string n, string u, string p) : Person(n, u, p), bookingCount(0), feedbackCount(0) {}

void Customer::addBooking(string booking) {
    if (bookingCount < 10)
        bookingHistory[bookingCount++] = booking;
}

void Customer::viewBookings() {
    cout << "\n--- Booking History ---\n";
    if (bookingCount == 0)
        cout << "No bookings yet.\n";
    for (int i = 0; i < bookingCount; i++)
        cout << bookingHistory[i] << endl;
}

void Customer::submitFeedback(string fb) {
    if (feedbackCount < 10)
        feedbackHistory[feedbackCount++] = fb;
}

void Customer::viewFeedbacks() {
    cout << "\n--- Feedback Submitted ---\n";
    if (feedbackCount == 0)
        cout << "No feedback yet.\n";
    for (int i = 0; i < feedbackCount; i++)
        cout << feedbackHistory[i] << endl;
}

void Customer::showProfile() {
    cout << "Customer Name: " << name << endl;
}
