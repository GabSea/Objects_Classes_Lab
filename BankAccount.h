//
// Created by CSStudent on 9/15/2026.
//

#ifndef UNTITLED_BANKACCOUNT_H
#define UNTITLED_BANKACCOUNT_H

#include <iostream>
class BankAccount {
    public:
        BankAccount();
        BankAccount(std::string, std::string, double);
        BankAccount(const BankAccount&);

        std::string getAccountNumber();
        std::string getAccountHolderName();
        double getBalance();

        void setAccountHolderName(std::string);

        void deposit(double);
        double withdraw(double);

        void print_details();

    private:
        std::string acc_num, acc_holder_name;
        double balance;

        void setAccountNumber(std::string);
        void setBalance(double);
};

#endif //UNTITLED_BANKACCOUNT_H
