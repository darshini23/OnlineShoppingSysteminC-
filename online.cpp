#include<iostream>  // program for online shopping system.
#include<fstream>
#include<cmath>  // For pow() function to calculate EMI
using namespace std;

class AdminLogin {
    public:
        // ADDITION OF PRODUCTS
        void Addproduct() {
            // Displaying products
            cout << "PRODUCTNAME\t\tPRODUCT ID\tPRICE";
            cout << "\nTV\t\t\t1\t\t56000";
            cout << "\nFRIDGE\t\t\t2\t\t50000";
            cout << "\nWASHINGMACHINE\t\t3\t\t45000";
            cout << "\nLAPTOP\t\t\t4\t\t34000";
            cout << "\nSMARTPHONE\t\t5\t\t12000";
            cout << "\nAC\t\t\t6\t\t67000";
            
            // Writing into a text file
            ofstream fobj("D://darshini1.txt");
            fobj << "PRODUCTNAME\tPRODUCT ID\tPRICE\n";
            fobj << "TV\t\t1\t\t56000\n";
            fobj << "FRIDGE\t\t2\t\t50000\n";
            fobj << "WASHINGMACHINE\t3\t\t45000\n";
            fobj << "LAPTOP\t\t4\t\t34000\n";
            fobj << "SMARTPHONE\t5\t\t12000\n";
            fobj << "AC\t\t6\t\t67000\n";
            fobj.close();
        }
};

class AdminShow : public AdminLogin {
    public:
        int choice, x = 1;
        string product;
        double price, amt = 0, discountPercentage;

        double interestRate = 0.12;  // 12% annual interest rate for EMI

        // Function to automatically calculate the discount percentage based on the product choice
        double getDiscountPercentage(int choice) {
            switch(choice) {
                case 1: 
				return 10.0;  // TV: 10% discount
                case 2: 
				return 8.0;   // Fridge: 8% discount
                case 3: 
				return 12.0;  // Washing Machine: 12% discount
                case 4: 
				return 7.0;   // Laptop: 7% discount
                case 5: 
				return 5.0;   // Smartphone: 5% discount
                case 6: 
				return 10.0;  // AC: 10% discount
                default: 
				return 0.0;  // No discount for invalid choice
            }
        }

        void viewproduct() {
            while (x == 1) {
                cout << "\nProduct to buy (enter product number): ";
                cin >> choice;
                cout << "\n1.TV\n2.FRIDGE\n3.WASHING MACHINE\n4.LAPTOP\n5.SMARTPHONE\n6.AC";

                // Get discount percentage automatically based on the product choice
                discountPercentage = getDiscountPercentage(choice);

                if (choice == 1) {
                    cout << "\nSelected: TV";
                    price = 56000;
                } 
                else if (choice == 2) {
                    cout << "\nSelected: FRIDGE";
                    price = 50000;
                } 
                else if (choice == 3) {
                    cout << "\nSelected: WASHING MACHINE";
                    price = 45000;
                } 
                else if (choice == 4) {
                    cout << "\nSelected: LAPTOP";
                    price = 34000;
                } 
                else if (choice == 5) {
                    cout << "\nSelected: SMARTPHONE";
                    price = 12000;
                } 
                else if (choice == 6) {
                    cout << "\nSelected: AC";
                    price = 67000;
                } 
                else {
                    cout << "\nInvalid choice";
                    continue;
                }

                // Calculate discount based on percentage
                double discountAmount = price * (discountPercentage / 100);
                amt += (price - discountAmount); // Apply discount and add to total amount

                cout << "\nPrice after applying " << discountPercentage << "% discount: " << price - discountAmount;
                cout << "\nTotal Amount so far: " << amt;

                cout << "\nDo you want to buy another product? (1 for Yes, 0 for No): ";
                cin >> x;
            }
        }

        void calculateEMI(double principal, int tenureInMonths) {
            double monthlyInterestRate = interestRate / 12;  // Convert annual interest rate to monthly rate
            double EMI = (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, tenureInMonths)) /
                         (pow(1 + monthlyInterestRate, tenureInMonths) - 1);
            cout << "\nMonthly EMI for " << tenureInMonths << " months is: " << EMI << "\n";
        }

        void finalamount() {
            double Cash;
            int emiOption, tenure;

            cout << "\nFinal amount to pay: " << amt;
            cout << "\nWould you like to pay using EMI option? (1 for Yes, 0 for No): ";
            cin >> emiOption;

            if (emiOption == 1) {
                cout << "\nEnter EMI tenure in months (e.g., 6, 8): ";
                cin >> tenure;
                calculateEMI(amt, tenure);
            } 
            else {
                cout << "\nEnter the cash: ";
                cin >> Cash;

                if (Cash >= amt) {
                    cout << "\nPurchase successful. Change: " << Cash - amt;
                } 
                else {
                    cout << "\nNot enough cash. Transaction failed.";
                }
            }
        }
};

int main() {
    AdminShow a;
    a.Addproduct();
    a.viewproduct();
    a.finalamount();
    return 0;
}

