#include "BankAccount.h"

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    assert ((dollars >= 0) && (cents >= 0) && (rate >= 0));

    balance = dollars+cents/100.0;
    interest_rate = rate;
}


BankAccount::BankAccount(int dollars, double rate)
{
    assert ((dollars >= 0) && (rate >= 0));

    balance = dollars;
    interest_rate = rate;
}

BankAccount::BankAccount( ) : balance(0), interest_rate(0.0)
{
    //Body intentionally empty
}



void BankAccount::update( )
{
    balance = balance + fraction(interest_rate)*balance;
}

double BankAccount::fraction(double percent_value)
{
    return (percent_value/100.0);
}



double BankAccount::get_balance( )
{
    return balance;
}

double BankAccount::get_rate( )
{
    return interest_rate;
}

//Uses iostream:
void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}
