//
// Created by CSStudent on 9/15/2026.
//

#include "BankAccount.h"

BankAccount::BankAccount() {
    this->acc_num = "-1";
    this->acc_holder_name = "EMPTY";
    this->balance = 0.0;
}
BankAccount::BankAccount(std::string acc_num, std::string acc_name, double balance) {
    this->acc_num = acc_num;
    this->acc_holder_name = acc_name;
    this->balance = balance;
}
BankAccount::BankAccount(const BankAccount& other) {
    this->acc_num = other.acc_num;
    this->acc_holder_name = other.acc_holder_name;
    this->balance = other.balance;
}

std::string BankAccount::getAccountNumber() {
    return this->acc_num;
}
std::string BankAccount::getAccountHolderName() {
    return this->acc_holder_name;
}
double BankAccount::getBalance() {
    return this->balance;
}

void BankAccount::setAccountHolderName(std::string acc_name) {
    this->acc_holder_name = acc_name;
}
void BankAccount::setAccountNumber(std::string acc_num) {
    this->acc_num = acc_num;
}
void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

void BankAccount::deposit(double amount) {
    this->balance += amount;
}
double BankAccount::withdraw(double amount) {
    double current_balance = this->balance;
    double balance_taken = amount;

    if (current_balance > amount) {
        std::cout << "The amount is greater than the account balance.\nWithdraw canceled." << std::endl;
        return 0.0;
    }

    this->balance -= amount;
    return balance_taken;
}

void BankAccount::print_details() {
    std::cout << this->getAccountHolderName() << "'s Account:\n"
                 "#:        " << this->getAccountNumber() << "\n"
                 "Balance:  " << this->getBalance() << "\n" << std::endl;
}