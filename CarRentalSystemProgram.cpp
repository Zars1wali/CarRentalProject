#include <iostream>
#include <string>
using namespace std;

// ======= Color Codes =======
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

// ======= Base class Person (Abstract) =======
class Person {
protected:
    string name, username, password;
public:
    Person(string n = "", string u = "", string p = "") : name(n), username(u), password(p) {}
    virtual void showProfile() = 0;
    string getUsername() { return username; }
    string getPassword() { return password; }
    void setPassword(string newPass) { password = newPass; } // NEW FEATURE
};

// ======= Derived class Customer =======
class Customer : public Person {
private:
    string bookingHistory[10];
    string feedbackHistory[10];
    int bookingCount;
    int feedbackCount;
public:
    Customer(string n = "", string u = "", string p = "") : Person(n, u, p), bookingCount(0), feedbackCount(0) {}

    void addBooking(string booking) {
        if (bookingCount < 10)
            bookingHistory[bookingCount++] = booking;
    }
    void viewBookings() {
        cout << "\n" << CYAN << "--- Booking History ---" << RESET << endl;
        if (bookingCount == 0)
            cout << "No bookings yet." << endl;
        for (int i = 0; i < bookingCount; i++)
            cout << bookingHistory[i] << endl;
    }
    void submitFeedback(string fb) {
        if (feedbackCount < 10)
            feedbackHistory[feedbackCount++] = fb;
    }
    void viewFeedbacks() {
        cout << "\n" << CYAN << "--- Feedback Submitted ---" << RESET << endl;
        if (feedbackCount == 0)
            cout << "No feedback submitted yet." << endl;
        for (int i = 0; i < feedbackCount; i++)
            cout << feedbackHistory[i] << endl;
    }
    int getFeedbackCount() { return feedbackCount; }
    string getFeedback(int i) { return feedbackHistory[i]; }
    void showProfile() override {
        cout << "Customer Name: " << name << endl;
    }
};

// ======= Derived class Admin =======
class Admin : public Person {
public:
    Admin(string n = "", string u = "", string p = "") : Person(n, u, p) {}
    void showProfile() override {
        cout << "Admin Name: " << name << endl;
    }
};

// ======= Base class Vehicle =======
class Vehicle {
protected:
    string brand, model;
    double pricePerDay;
    bool available;
public:
    Vehicle(string b = "", string m = "", double price = 0) : brand(b), model(m), pricePerDay(price), available(true) {}

    virtual void displayInfo() {
        cout << brand << " " << model << " - $" << pricePerDay << "/day " << (available ? "(Available)" : "(Rented)") << endl;
    }
    bool isAvailable() { return available; }
    void rentOut() { available = false; }
    void returnBack() { available = true; }
    string getDetails() { return brand + " " + model; }
    double getPrice() { return pricePerDay; }
};

// ======= Derived Vehicles =======
class Sedan : public Vehicle {
public:
    Sedan(string b, string m, double price) : Vehicle(b, m, price) {}
    void displayInfo() override {
        cout << "Sedan: ";
        Vehicle::displayInfo();
    }
};

class SUV : public Vehicle {
public:
    SUV(string b, string m, double price) : Vehicle(b, m, price) {}
    void displayInfo() override {
        cout << "SUV: ";
        Vehicle::displayInfo();
    }
};

class Truck : public Vehicle {
public:
    Truck(string b, string m, double price) : Vehicle(b, m, price) {}
    void displayInfo() override {
        cout << "Truck: ";
        Vehicle::displayInfo();
    }
};

// ======= Booking class =======
class Booking {
private:
    Vehicle* vehicle;
    int days;
public:
    Booking(Vehicle* v = nullptr, int d = 0) : vehicle(v), days(d) {}

    double calculateTotal() {
        if (vehicle != nullptr)
            return vehicle->getPrice() * days;
        else return 0;
    }
};

// ======= Car Rental System class =======
class CarRentalSystem {
private:
    Vehicle* vehicles[10];
    int vCount;
    Customer customers[5];
    Admin admin;
    int cCount;
    Customer* loggedInCustomer;

public:
    CarRentalSystem() : vCount(0), cCount(0), admin("Admin", "admin", "admin123"), loggedInCustomer(nullptr) {}

    void addVehicle(Vehicle* v) {
        if (vCount < 10) vehicles[vCount++] = v;
    }

    void showVehicles() {
        cout << "\n" << CYAN << "--- Available Vehicles ---" << RESET << "\n";
        for (int i = 0; i < vCount; i++) {
            cout << (i + 1) << ". ";
            vehicles[i]->displayInfo();
        }
    }

    void registerCustomer() {
        if (cCount < 5) {
            string name, username, password;
            cout << "\nEnter your Name: "; cin >> name;
            cout << "Choose Username: "; cin >> username;
            cout << "Choose Password: "; cin >> password;
            customers[cCount++] = Customer(name, username, password);
            cout << GREEN << "✅ Registration Successful!" << RESET << endl;
        } else {
            cout << RED << "❌ Customer registration limit reached!" << RESET << endl;
        }
    }

    bool customerLogin() {
        string u, p;
        cout << "Enter Username: "; cin >> u;
        cout << "Enter Password: "; cin >> p;
        for (int i = 0; i < cCount; i++) {
            if (customers[i].getUsername() == u && customers[i].getPassword() == p) {
                loggedInCustomer = &customers[i];
                cout << GREEN << "\n✅ Customer Login Successful!\n" << RESET;
                cout << CYAN << "Welcome, " << u << "!\n" << RESET; // Welcome Message
                return true;
            }
        }
        cout << RED << "❌ Invalid Credentials!\n" << RESET;
        return false;
    }

    bool adminLogin() {
        string u, p;
        cout << "Enter Admin Username: "; cin >> u;
        cout << "Enter Admin Password: "; cin >> p;
        if (admin.getUsername() == u && admin.getPassword() == p) {
            cout << GREEN << "\n✅ Admin Login Successful!\n" << RESET;
            cout << CYAN << "Welcome, Admin!\n" << RESET; // Welcome Message
            return true;
        } else {
            cout << RED << "❌ Invalid Admin Credentials!\n" << RESET;
            return false;
        }
    }

    void forgotPassword() {
        string u;
        cout << "Enter your Username: "; cin >> u;
        for (int i = 0; i < cCount; i++) {
            if (customers[i].getUsername() == u) {
                cout << YELLOW << "Your password is: " << customers[i].getPassword() << RESET << endl;
                return;
            }
        }
        cout << RED << "❌ Username not found!" << RESET << endl;
    }

    void customerMenu() {
        int choice;
        do {
            cout << "\n" << CYAN << "=== Customer Menu ===" << RESET << endl;
            cout << "1. View Vehicles\n";
            cout << "2. Rent a Vehicle\n";
            cout << "3. Return a Vehicle\n";
            cout << "4. View Booking History\n";
            cout << "5. Submit Feedback\n";
            cout << "6. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                showVehicles();
            }
            else if (choice == 2) {
                int select, days;
                showVehicles();
                cout << "Select Vehicle No: "; cin >> select;
                cout << "Enter Number of Days: "; cin >> days;
                if (days > 30) {
                    cout << RED << "❌ Cannot rent for more than 30 days!" << RESET << endl;
                    continue;
                }
                if (select > 0 && select <= vCount && vehicles[select - 1]->isAvailable()) {
                    Booking b(vehicles[select - 1], days);
                    double total = b.calculateTotal();
                    vehicles[select - 1]->rentOut();
                    loggedInCustomer->addBooking(vehicles[select - 1]->getDetails() + " for " + to_string(days) + " days ($" + to_string(total) + ")");
                    cout << GREEN << "\n✅ Vehicle Booked Successfully!\n" << RESET;
                    cout << CYAN << "----- RECEIPT -----\n" << RESET;
                    cout << "Vehicle: " << vehicles[select - 1]->getDetails() << endl;
                    cout << "Days: " << days << endl;
                    cout << "Total Amount: $" << total << endl;
                    cout << CYAN << "-------------------\n" << RESET;
                } else {
                    cout << RED << "❌ Invalid Vehicle Selection!\n" << RESET;
                }
            }
            else if (choice == 3) {
                showVehicles();
                int select;
                cout << "Select Vehicle No to Return: "; cin >> select;
                if (select > 0 && select <= vCount && !vehicles[select - 1]->isAvailable()) {
                    vehicles[select - 1]->returnBack();
                    cout << GREEN << "✅ Vehicle Returned Successfully!" << RESET << endl;
                } else {
                    cout << RED << "❌ Invalid Selection or Already Available!" << RESET << endl;
                }
            }
            else if (choice == 4) {
                loggedInCustomer->viewBookings();
            }
            else if (choice == 5) {
                cin.ignore();
                string fb;
                cout << "Enter Feedback: ";
                getline(cin, fb);
                loggedInCustomer->submitFeedback(fb);
                cout << GREEN << "✅ Feedback Submitted!" << RESET << endl;
            }
            else if (choice == 6) {
                cout << YELLOW << "Logging Out..." << RESET << endl;
                loggedInCustomer = nullptr;
            }
            else {
                cout << RED << "❌ Invalid Choice!" << RESET << endl;
            }
        } while (choice != 6);
    }

    void adminMenu() {
        int choice;
        do {
            cout << "\n" << CYAN << "=== Admin Menu ===" << RESET << endl;
            cout << "1. Add Vehicle\n";
            cout << "2. View Vehicles\n";
            cout << "3. View Customer Feedbacks\n";
            cout << "4. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;
            if (choice == 1) {
                string brand, model;
                double price;
                int type;
                cout << "Enter Brand: "; cin >> brand;
                cout << "Enter Model: "; cin >> model;
                cout << "Enter Price/Day: "; cin >> price;
                cout << "Enter Type (1-Sedan, 2-SUV, 3-Truck): "; cin >> type;
                if (type == 1) addVehicle(new Sedan(brand, model, price));
                else if (type == 2) addVehicle(new SUV(brand, model, price));
                else if (type == 3) addVehicle(new Truck(brand, model, price));
                else cout << RED << "❌ Invalid Type!\n" << RESET;
            }
            else if (choice == 2) {
                showVehicles();
            }
            else if (choice == 3) {
                cout << "\n" << CYAN << "--- Customer Feedbacks ---" << RESET << endl;
                for (int i = 0; i < cCount; i++) {
                    cout << YELLOW << customers[i].getUsername() << ":" << RESET << endl;
                    customers[i].viewFeedbacks();
                }
            }
            else if (choice == 4) {
                cout << YELLOW << "Logging Out..." << RESET << endl;
            }
            else {
                cout << RED << "❌ Invalid Choice!" << RESET << endl;
            }
        } while (choice != 4);
    }

    void mainMenu() {
        int choice;
        do {
            cout << "\n" << BOLD << CYAN << "=== Welcome to Car Rental System ===" << RESET << endl;
            cout << "1. Register as Customer\n";
            cout << "2. Customer Login\n";
            cout << "3. Admin Login\n";
            cout << "4. Forgot Password\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            if (choice == 1) {
                registerCustomer();
            }
            else if (choice == 2) {
                if (customerLogin()) customerMenu();
            }
            else if (choice == 3) {
                if (adminLogin()) adminMenu();
            }
            else if (choice == 4) {
                forgotPassword();
            }
            else if (choice == 5) {
                cout << GREEN << "Thank you for using Car Rental System!" << RESET << endl;
            }
            else {
                cout << RED << "❌ Invalid Choice!" << RESET << endl;
            }
        } while (choice != 5);
    }
};

// ======= Main Function =======
int main() {
    CarRentalSystem crs;
    crs.mainMenu();
    return 0;
}
