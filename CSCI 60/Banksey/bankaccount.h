#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <cassert>


class BankAccount{
private:
    int bank_number;
    double account_balance;
    int ssn;
    std::string name;
public:
    double withdraw(double amount);
    //pre:  amount>=0
    //Post:  Deducts amount money from the account, and returns how much money is left in the account.
    //$30 overdraft fee is applied if necessary.
    double deposit(double amount);
    //precondition:  amount >=0
    //postcondition:  Adds amount money to the account, returns the new balance.
    BankAccount(int ba, double bal, int s, std::string n);
    //Pre:  ba>0, bal>=0, s>0, n!=""
    //Post:  Sets balance = bal, bank_number=ba, ssn=s, name=n
    BankAccount();
    //Pre:  none
    //Post:  Set balance to 0, ssn and bank_number to -1, name to ""
    BankAccount(double bal);
    double get_balance(){return account_balance;}
    //Pre:  none
    //Post:  Returns the balance

};



#endif // BANKACCOUNT_H
