# CarRentalProject
===========================================
         CAR RENTAL SYSTEM (C++)
===========================================

Project Type  : Console-based C++ Project  
Developed By  : [Umer Wali - 2023736 / Suleman Malik 2024472]  
Date          : April 2025  
Version       : 1.0

-------------------------------------------
🔧 HOW TO COMPILE & RUN
-------------------------------------------

1. Make sure you have a C++ compiler (e.g., g++) installed.

2. Open terminal or command prompt and navigate to the folder containing all .cpp and .h files.

3. Compile the project:
   g++ main.cpp Customer.cpp Admin.cpp Vehicle.cpp Utils.cpp -o CarRentalSystem

4. Run the project:
   ./CarRentalSystem   (Linux/macOS)
   CarRentalSystem.exe (Windows)

-------------------------------------------
📂 FILE STRUCTURE
-------------------------------------------

main.cpp              → Entry point, handles login and menu
Customer.cpp/.h       → Customer functions (Rent, Return, Feedback, Forgot Password)
Admin.cpp/.h          → Admin functions (View Customers, View Feedbacks)
Vehicle.cpp/.h        → Vehicle management
Utils.cpp/.h          → Helper functions (UI, data validation, file I/O)
Data/
 ├── customers.txt    → Stores customer records
 ├── vehicles.txt     → Stores vehicle list
 ├── feedback.txt     → Stores feedback
 └── receipts/        → Stores printed bill receipts

-------------------------------------------
🔐 LOGIN CREDENTIALS
-------------------------------------------

Admin:
  Username: admin
  Password: admin123

Customers:
  Customers must register before renting.
  Password recovery is available via "Forgot Password".

-------------------------------------------
✨ FEATURES
-------------------------------------------

✅ Welcome screen with colorful UI  
✅ Admin login to view customers & feedbacks  
✅ Customer registration & login  
✅ Rent a vehicle with daily charges  
✅ Limit of 30 days max rental enforced  
✅ Automatic bill receipt printed on rent  
✅ Return vehicle with confirmation  
✅ Leave feedback after return  
✅ "Forgot Password" option for recovery  
✅ Colorful menu and user-friendly interface  
✅ File-based data storage (no database needed)  

-------------------------------------------
📜 NOTES
-------------------------------------------

- Ensure the "Data" directory exists with write permission.
- Printed receipts will be stored inside the "receipts" folder.
- All data is saved in plain text files.

-------------------------------------------
📧 CONTACT
-------------------------------------------

Developed by: [Umer Wali-2023736 / Suleman Malik-2024472]    
GitHub: https://github.com/yourusername/carrentalproject-cpp  

===========================================
