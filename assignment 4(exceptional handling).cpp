#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Account 
{
  private:
    string name;
    double balance;

  public:

    Account(string n, double b) : name(n), balance(b)
    {
        if (balance < 0)
        {
            throw invalid_argument("Initial balance cannot be negative.");
        }

        cout << "Constructor called for account class." << endl;
        cout << "Account created for " << name << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw runtime_error("Insufficient balance.");
        }

        balance -= amount;
        cout << "Withdraw Amount: " << amount << endl;
        cout << "Remaining Balance: " << balance << endl;
    }

    ~Account()
    {
        cout << "Destructor called for account class." << endl;
        cout << "Account closed for " << name << endl;
    }
};

int main()
{
    try
    {
        Account a1("Fatima", -26);
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    cout << endl;

    try
    {
        Account a2("Ania", 6091);

        try
        {
            a2.withdraw(1200);
        }
        catch (exception &e)
        {
            cout << "Withdraw Error: " << e.what() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    cout << endl;
    cout << "Program finished safely." << endl;

    
    return 0;
}