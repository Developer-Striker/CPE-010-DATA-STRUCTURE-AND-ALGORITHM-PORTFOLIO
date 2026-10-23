#include <iostream>

using namespace std;

int main() {

float item, item2, payment, change = 0;

cout << "=============================================" << "\n"
     << "|| \t   Input the item price:\t   || " << "\n"
     << "=============================================" << "\n";

while (true) {
    cout << " || Enter item price (or 0 to finish): ";
    cin >> item;

    if (item > 0 || item == 0) {
        item2 = item + item2;
        if (item == 0) {
            cout << "=============================================" <<"\n" 
                 << "Enter the payment amount: ";
            cin >> payment;

            change = payment - item2;

            if (change < 0) {
                cout << "Insufficient payment. Please try again.";
            } else {
                
                cout << "=============================================" << "\n"
                     << "Transaction: " << "\n" 
                     << "\n" << "total price amount: P" << item2 << "\n"
                     << "payment amount: P" << payment << "\n"
                     << "Change: " << change;
                break;
            }
        }
    } else if (item < 0) {
        cout << "Invalid item price. Please try again.";
        continue;
    }
}
}