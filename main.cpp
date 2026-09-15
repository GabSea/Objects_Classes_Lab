#include <iostream>
#include "BankAccount.h"
#include <vector>

/*  oaky so ill make a main menu that can display accounts or edit one specific account at a time
    for "security", ill make it so you have to enter in the account number to access it
    ofc the numbers will be listed but its a proof of concept.
    then once the number is entered ill have a sub-menu that lets you do everything in there.
    cool? cool. */

std::vector<BankAccount> bank_accounts;

void run_menu();
int main_menu();
int sub_menu(int);

BankAccount create_bank_account();
void erase_bank_account();
void edit_bank_account();

void display_accounts();

int main() {

    run_menu();

    return 0;
}

void run_menu() {
    int choice = 0;

    while (choice != -1) {

        choice = main_menu();

        switch (choice) {
            case 1:
                bank_accounts.push_back(create_bank_account());
                break;
            case 2:
                erase_bank_account();
                break;
            case 3:
                edit_bank_account();
                break;
            case 4:
                for (int i = 0; i < bank_accounts.size(); i++) {
                    bank_accounts[i].print_details();
                }
                break;
            case -1:
                std::cout << "bubyeee" << std::endl;
                break;
            default:
                std::cout << "....hhuwhat?." << std::endl;
        }

    }
}

int main_menu() {
    int choice = -1;
    std::cout << "--------------Main Menu-------------\n"
                 "Enter an input to choose what to do:\n"
                 "- 1. Add Bank Account\n"
                 "- 2. Delete Bank Account\n"
                 "- 3. Manage Bank Account\n"
                 "- 4. Display All Bank Accounts\n"
                 "- -1. Quit\n"
                 "..." << std::endl;
    std::cin >> choice;

    return choice;
}

int sub_menu(int choice) {
    int sub_choice = -1;
    std::cout << "------------Account Menu-----------\n"
                 "Editing " << bank_accounts.at(choice).getAccountHolderName() << "'s Account..." << std::endl;
    std::cout << "Enter an input to choose what to do:\n"
                 "- 1. Deposit\n"
                 "- 2. Withdraw\n"
                 "- 3. Change Name\n"
                 "- 4. Display info\n"
                 "- -1. Quit\n"
                 "..." << std::endl;
    std::cin >> choice;

    return choice;
}

BankAccount create_bank_account() {
    std::string acc_num, name;
    double balance;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter balance: " << std::endl;
    std::cin >> balance;

    unsigned int x = std::rand() % 2000000;

    acc_num = std::to_string(x);


    BankAccount acc(acc_num, name, balance);
    acc.print_details();
    return acc;
}

void erase_bank_account() {
    int deletion_choice = 0;
    int confirmation = 0;

    std::cout << "Active Accounts:" << std::endl;

    for (int i = 0; i < bank_accounts.size(); i++) {
        std::cout << "ID: " << i << ":\n";
        bank_accounts[i].print_details();
    }

    std::cout << "Choose ID to delete" << std::endl;
    std::cin >> deletion_choice;

    if (deletion_choice > bank_accounts.size()) {
        std::cout << "Invalid ID." << std::endl;
        return;
    }

    std::cout << "Confirm deletion of:\n";
    bank_accounts[deletion_choice].print_details();
    std::cout << "Type \"1\" to confirm." << std::endl;

    std::cin >> confirmation;

    if (confirmation == 1) {
        bank_accounts.erase(bank_accounts.begin() + deletion_choice);
    } else {
        std::cout << "Deletion canceled." << std::endl;
    }
}

void edit_bank_account() {
    std::string acc_num;
    int editing = -1;

    std::cout << "Type account number of account to edit: " << std::endl;
    std::cin >> acc_num;

    for (int i = 0; i < bank_accounts.size(); i++) {
        if (acc_num == bank_accounts[i].getAccountNumber()) {
            editing = i;
        }
    }

    if (editing == -1) {
        std::cout << "Invalid account number." << std::endl;
        return;
    }

    int choice = 0;

    while (choice != -1) {

        choice = sub_menu(editing);
        double deposit;
        double withdraw;
        std::string n;

        switch (choice) {
            case 1:
                std::cout << "Enter deposit amnt: " << std::endl;
                std::cin >> deposit;
                bank_accounts[editing].deposit(deposit);
                break;
            case 2:
                std::cout << "Enter withdraw amnt: " << std::endl;
                std::cin >> withdraw;
                bank_accounts[editing].withdraw(withdraw);
                break;
            case 3:
                std::cout << "Enter new name: " << std::endl;
                std::cin >> n;
                bank_accounts[editing].setAccountHolderName(n);
                break;
            case 4:
                bank_accounts[editing].print_details();
                break;
            case -1:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "what.???" << std::endl;
                break;
        }
    }

}