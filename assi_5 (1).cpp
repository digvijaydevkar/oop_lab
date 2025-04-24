#include <iostream>
#include <string>
using namespace std;

class Bank 
{
public:
    void deposit(int amount) 
	{
        cout << "Depositing " << amount << " in cash." << endl;
    }

    void deposit(float amount) 
	{
        cout << "Depositing " << amount << " via digital payment." << endl;
    }

    void deposit(string upiID) 
	{
        cout << "Depositing an amount using UPI (" << upiID << ").\n" << endl;
    }
};

class Account 
{
private:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}

    void display() 
	{
        cout << "Account " << accountNumber << " Balance: Rupees " << balance << endl;
    }

    
    float getBalance() const 
	{
        return balance;
    }

    friend void transfer(Account &from, Account &to, float amount);

    Account operator+(float amount) 
	{
        return Account(accountNumber, balance + amount);
    }
    
    
    Account operator-(float amount) 
	{
        if (balance >= amount) 
		{
            return Account(accountNumber, balance - amount);
        }
		else
		{
            cout << "Insufficient balance!" << endl;
            return *this;  
        }
    }
};


void transfer(Account &from, Account &to, float amount) 
{
    if (from.balance >= amount) 
	{
        from.balance -= amount;
        to.balance += amount;
        cout << "\nTransferring Rupees " << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << "...\n" << endl;
    }
	else
	{
        cout << "Insufficient balance for transfer!" << endl;
    }
}

int main()
{
    Bank bank;
    bank.deposit(5000);
    bank.deposit(1500.75f);
    bank.deposit("gpay@upi");

    Account acc1(1, 10000);
    Account acc2(2, 5000);

    acc1.display();
    acc2.display();

    transfer(acc1, acc2, 3000);  // Transfer money

    acc1.display();
    acc2.display();

    acc1 = acc1 - 2000;  // Withdraw money
    cout << "\nWithdrawing Rupees " << 2000 << " from Account 1..." << endl;
    acc1.display();

    return 0;
}

