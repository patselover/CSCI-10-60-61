#include "bankaccount.h"


BankAccount::BankAccount(){
    bank_number=111;
    ssn=111;
    account_balance=0;
    name="Bob";
}
BankAccount::BankAccount(double bal){

    account_balance=bal;
}
BankAccount::BankAccount(int ba, double bal, int s, std::string n){
    assert(n!="" && ba>0 && s>0 && bal >=0);
    bank_number=ba;
    ssn=s;
    account_balance=bal;
    name=n;
}

double BankAccount::withdraw(double amount){
    assert(amount >= 0);
    if(account_balance<amount){
        double overdraft_fee = 30;
        account_balance=account_balance-overdraft_fee;
    }

    account_balance=account_balance-amount;
    return account_balance;
}
double BankAccount::deposit(double amount){
    assert(amount >= 0);
    account_balance+=amount;
    return account_balance;
}




