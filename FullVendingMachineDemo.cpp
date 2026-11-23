#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int CARD_PIN = 4821;
const int MAX_PIN_TRIES = 3;

struct Item {
    string name;
    double price;
    int stock;
};

void printMachine(const vector<Item>& items) {
    cout << "\n ==============================================\n";
    cout << " |               VIRO VENDOR                  |\n";
    cout << " |          *** CARD PAYMENT ONLY ***         |\n";
    cout << " |--------------------------------------------|\n";
    for (size_t i = 0; i < items.size(); i++) {
        cout << " | [" << i + 1 << "] " << left << setw(30) << items[i].name
             << right << fixed << setprecision(2) << "$" << setw(6) << items[i].price;
        if (items[i].stock == 0) {
            cout << " SOLD OUT |\n";
        } else {
            cout << "  x" << setw(2) << items[i].stock << " |\n";
        }
    }
    cout << " |--------------------------------------------|\n";
    cout << " |  [ CARD READER ]        [ DISPENSE ]       |\n";
    cout << " ==============================================\n";
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Please enter a whole number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

bool checkCardPin() {
    for (int attempt = 1; attempt <= MAX_PIN_TRIES; attempt++) {
        int attemptsLeft = MAX_PIN_TRIES - attempt + 1;
        cout << "Attempts remaining: " << attemptsLeft << "\n";

        int pin = readInt("Enter card PIN: ");
        if (pin == CARD_PIN) {
            return true;
        }
        cout << "Incorrect PIN.\n";
    }
    return false;
}

void buyItem(vector<Item>& items, double& cardBalance) {
    printMachine(items);
    int choice = readInt("\nEnter item number (0 to cancel): ");
    if (choice == 0) {
        cout << "Purchase cancelled.\n";
        return;
    }
    if (choice < 1 || choice > static_cast<int>(items.size())) {
        cout << "Invalid item number.\n";
        return;
    }

    Item& item = items[choice - 1];
    if (item.stock == 0) {
        cout << item.name << " is SOLD OUT.\n";
        return;
    }

    cout << "You selected: " << item.name << " ($" << fixed << setprecision(2)
         << item.price << ")\n";
    cout << "Card payment only. Cash is not accepted.\n";
    cout << "Charging $" << fixed << setprecision(2) << item.price << " to card.\n";

    if (!checkCardPin()) {
        cout << "Card declined: too many incorrect PIN attempts. Transaction cancelled.\n";
        return;
    }

    if (cardBalance < item.price) {
        cout << "Card declined: insufficient funds. Transaction cancelled.\n";
        return;
    }

    cardBalance -= item.price;
    cout << "Payment approved.\n";
    item.stock--;
    cout << "Dispensing " << item.name << "...\n";
    cout << "Thank you for shopping at Viro Vendor!\n";
}

int main() {
    vector<Item> items = {
        {"Diet Coke", 2.50, 5},
        {"KitKat Bar", 1.50, 5},
        {"Kinder Bueno 2 Pack", 2.35, 5},
        {"1 Pack Lrg Soft Chocolate Chip Cookie", 2.90, 5}
    };

    double cardBalance = 30.00;

    cout << "Welcome to the Viro Vending Machine!\n";
    cout << "NOTICE: This machine accepts CARD PAYMENT ONLY. Cash is not accepted.\n";

    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Buy an item (card)\n";
        cout << "0. Exit\n";
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1:
                buyItem(items, cardBalance);
                break;
            case 0:
                cout << "Shutting down the vending machine. Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}