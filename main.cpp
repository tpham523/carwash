
#include <iostream>
#include <string>
#include "customer.h"
#include <queue>
#include <vector>

using namespace std;

void Menu();      // Menu that displays options.
void CheckIn();   // Check in a customer.
void CheckOut();  // Remove customer from list.
void Search();    // Search for a customer.
void Quit();      // Quit program.

std::queue<Customer> customerDatabase;
std::vector<Customer> customerHistory;

int main() {
    bool loop = true;
    int selection;
    

    do {
        Menu();
        cout << "Input: ";
        cin >> selection;
        cin.ignore();

        switch (selection)
        {
        case 1:
            cout << endl;
            CheckIn();
            cout << endl;
            break;
        case 2:
            cout << endl;
            CheckOut();
            cout << endl;
            break;
        case 3:
            cout << endl;
            Search();
            cout << endl;
            break;
        case 4:
            cout << endl;
            Quit();
            loop = false;
            cout << "Exiting program...\n";
            break;
        default:
            break;
        }

    } while (loop);
}

void Menu() {
    cout << "1) Check in\n";
    cout << "2) Check out\n";
    cout << "3) Search\n";
    cout << "4) Quit\n";
}

void CheckIn() {

    // Check in: Checks in the customer. 
    // The user will be asked to insert the name of the customer, 
    // the license plate number, and whether or not the customer wants a premium wash.
    string customerName;
    string licPlate;
    bool _premium;
    char answer;
    
    std::cout << "What is your name? " << std::endl;
    std::cin >> customerName;

    std::cout << "What is your license plate number? " << std::endl;
    std::cin >> licPlate;

    std::cout << "Do you want premium wash? Type Y/N. " << std::endl;
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y') 
        _premium = true;
    else if (answer == 'n' || answer == 'N')
        _premium = false;
    else 
        std::cout << "Please enter Y or N." << std::endl;

    Customer newCustomer(customerName, licPlate, _premium);
    customerDatabase.push(newCustomer);

    std::cout << customerName + " checked in.";
}

void CheckOut() {
    // Check out: Checks out the next customer. A notification stating which customer has been checked out will be displayed. 
    // Checked out customers will be stored in a history database.
    
    Customer checkedOutCustomer = customerDatabase.front();

    customerDatabase.pop();
    customerHistory.push_back(checkedOutCustomer);

    std::cout << checkedOutCustomer.get_name() + " checked out" << std::endl;
}

void Search() {
    // Search: Searches the history database for a customer. The customer’s details will be printed.
    string cName;

    std::cout << "What is your name? " << std::endl;
    std::cin >> cName;
    

    for (int i = 0; i < customerHistory.size(); i++) {
        if (customerHistory[i].get_name() == cName) {
            std::cout << customerHistory[i];
        }
        else
        {
            std::cout << "Customer not found.";
        }
        
    }
}

void Quit() {
    // Quit: Checks out the remaining customers, erases the history, and exits the program.
    Customer aCustomer;

    while (!customerDatabase.empty()) {
        aCustomer = customerDatabase.front();
        std::cout << aCustomer.get_name() + " checked out" << std::endl;
        customerDatabase.pop();
    }

    customerHistory.clear();

    std::cout << "Exiting the program...";


}
