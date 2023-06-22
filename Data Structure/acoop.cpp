#include<iostream>
#include<string>
using namespace std;

class Account {
    protected:
        string customer_name;
        int account_number;
        string account_type;
        double balance;
    public:
        Account(string name, int num, string type, double bal) {
            customer_name = name;
            account_number = num;
            account_type = type;
            balance = bal;
        }
        void deposit(double amount) {
            balance += amount;
            cout << "Deposit of " << amount << " successful" << endl;
        }
        void display_balance() {
            cout << "Current balance: " << balance << endl;
        }
        virtual void compute_interest() {}
        virtual void withdraw(double amount) {}
        virtual void check_minimum_balance() {}
};

class Cur_Acct : public Account {
    private:
        double minimum_balance;
        double penalty;
    public:
        Cur_Acct(string name, int num, string type, double bal) : Account(name, num, type, bal) {
            minimum_balance = 500;
            penalty = 50;
        }
        void compute_interest() {
            cout << "No interest is paid on current accounts" << endl;
        }
        void withdraw(double amount) {
            if (balance - amount < minimum_balance) {
                cout << "Withdrawal amount exceeds minimum balance" << endl;
            } else {
                balance -= amount;
                cout << "Withdrawal of " << amount << " successful" << endl;
                check_minimum_balance();
            }
        }
        void check_minimum_balance() {
            if (balance < minimum_balance) {
                balance -= penalty;
                cout << "Penalty of " << penalty << " imposed due to minimum balance not being maintained" << endl;
            }
        }
};

class Sav_Acct : public Account {
    private:
        double interest_rate;
    public:
        Sav_Acct(string name, int num, string type, double bal) : Account(name, num, type, bal) {
            interest_rate = 0.05;
        }
        void compute_interest() {
            double interest = balance * interest_rate;
            balance += interest;
            cout << "Interest of " << interest << " credited to account" << endl;
        }
        void withdraw(double amount) {
            if (balance - amount < 0) {
                cout << "Insufficient funds" << endl;
            } else {
                balance -= amount;
                cout << "Withdrawal of " << amount << " successful" << endl;
            }
        }
};

int main() {
    // Creating a current account
    Cur_Acct cur_acct("John Doe", 12345, "Current", 1000);
    cur_acct.display_balance();
    cur_acct.deposit(500);
    cur_acct.withdraw(800);
    cur_acct.display_balance();
    cur_acct.check_minimum_balance();
    cur_acct.withdraw(600);
    cur_acct.display_balance();
    cur_acct.check_minimum_balance();

    // Creating a savings account
    Sav_Acct sav_acct("Jane Doe", 67890, "Savings", 2000);
    sav_acct.display_balance();
    sav_acct.deposit(1000);
    sav_acct.compute_interest();
    sav_acct.display_balance();
    sav_acct.withdraw(500);
    sav_acct.display_balance();

    return 0;
}
