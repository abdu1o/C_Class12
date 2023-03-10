#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double _balance)
    {
        this->balance = _balance;
    }

    double Deposit(double amount)
    {
        return balance += amount;
    }

    void Withdraw(double amount)
    {
        if (amount > balance)
        {
            throw runtime_error("not enough money to withdraw!");
        }
        balance -= amount;
    }

    const double GetBalance() const
    {
        return balance;
    }
};


void TryCatch(BankAccount& account)
{
    try
    {
        account.Withdraw(50.0);
        cout << "Withdraw successful" << endl;
    }
    catch (const runtime_error& ex)
    {
        cerr << "Error: " << ex.what() << endl;
    }
}

int main()
{
    BankAccount account(10);

    cout << "Your balance: " << account.GetBalance() << endl;

    TryCatch(account);

    account.Deposit(500.0);
    cout << "Your balance: " << account.GetBalance() << endl;

    TryCatch(account);
}