#include<iostream>
using namespace std;

class Bank
{    
    private:
        double baln;  
        char name[50];
          
    public:
        void deposit(double money)
        {
            if(money > 0)
            {
                baln += money;
                cout << "\nMoney deposited successfully";
                cout << "\nYour current balance is " << baln;
            }
            else
                cout << "\nMoney amount should be positive";
        }
        void withdraw(double money)
        {
            if(baln >= money)
            {
                baln -= money;
                cout << "\nMoney withdrawn successfully";
                cout << "\nYour current balance is " << baln;
            }
            else
                cout << "\nInsufficient balance";
        }
        void viewBal()
        {
            cout << "Your account balance is " << baln;
        }

        void transfer(Bank &toAccount, double money)
        {
            if(baln >= money)  
            {
                baln -= money;  
                toAccount.baln += money;  
                cout << "\nMoney transferred successfully!";
                cout << "\nYour current balance is " << baln;
                cout << "\nRecipient's current balance is " << toAccount.baln;
            }
            else
                cout << "\nInsufficient balance to transfer";
        }
};
int main()
{
    Bank b1;
	Bank b2; 
    int opt;
    double am;

    while(1)
    {
        cout << "\nMenu:\n 1. Money Deposit\n 2. Money Withdraw\n 3. View Bank Balance\n 4. Transfer Money\n 5. Exit" << endl;
        cin >> opt;

        if(opt == 5)
        {
            cout << "Thank you! ...\n"; 
            break;
        }

        switch(opt)
        {
            case 1:
                cout << "\nEnter amount to deposit: ";
                cin >> am;
                b1.deposit(am);  
                break;

            case 2:
                cout << "\nEnter amount to withdraw: ";
                cin >> am;
                b1.withdraw(am); 
                break;

            case 3:
                b1.viewBal();  
                break;
                
            case 4:
                cout << "\nEnter amount to transfer: ";
                cin >> am;
                b1.transfer(b2, am); 
                break;
            default:
                cout << "\nInvalid option. Please try again.";
        }
    }
    return 0;
}
