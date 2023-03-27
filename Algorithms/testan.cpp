#include <iostream>
#include <fstream>
#include <strstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

#define OUT(X) std::cout<< X <<endl;


class Cur_acct;
class Account;

class Account
{
    private:
        string customer_name = " ";
        string type_account = " ";
        int account_no = 0;
        double Balance = 0;

    public:
        // Account(string name, int number, string type, double initial_balance)
        // {
        // customer_name = name;
        // account_no = number;
        // type_account = type;
        // Balance = initial_balance;
        // }
        void Account::Account_Details(Account accArr[],int numOfAccounts);
        void print();
        string getCustomerName() const { return customer_name; }
        string getAccountType() const { return type_account; }
        int getAccountNumber() const { return account_no; }
        double getBalance() const { return Balance; }
        
        ~Account();
    };

    void Account::print()
    {
        cout<<Balance;
    }
void Account::Account_Details(Account accArr[],int numOfAccounts) {
    int selection;
    bool unique = false;
    ifstream infile("accounts.txt");
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file for reading!" << endl;
        return;
    }
    OUT("Customer Name:");
    cin >> customer_name;
    do {
        OUT("Account Number:");
        cin >> account_no;
        unique = true;
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string field;
            std::getline(ss, field, ':'); // get the field name
            getline(ss, field); // get the field value
            field.erase(0, field.find_first_not_of(' ')); // remove leading spaces
            field.erase(field.find_last_not_of(' ') + 1); // remove trailing spaces
            if (field == to_string(account_no)) {
                unique = false;
                OUT("Account Number already exists. Please enter a different number.");
                break;
            }
        }
        if (!unique) {
            infile.clear();
            infile.seekg(0, ios::beg); // reset the file pointer to the beginning
            continue; // start over from the top of the while loop
        }
    } while (!unique);
    infile.close();
    do {
        cout << "Choose Banking Account" << endl << "1.Savings Account" << endl << "2.Current Account" << endl;
        cin >> selection;
        if (selection == 1) {
            type_account = "Saving Account";
            break;
        } else if (selection == 2) {
            type_account = "Current Account";
            break;
        } else {
            OUT("Invalid Choice");
            break;
        }
    } while (true);
}
Account::~Account()
{
}

class Cur_acct : public Account
{
private:
    const int minBalance= 1000;
    const int serviceCharge = 500;
    
public:
    int deposit(Account& acc);
    void checkBalance(int bal, Account& acc);
    ~Cur_acct();
};

int Cur_acct::deposit(Account& acc)
{
    int dep;
    double balance = acc.getBalance();
    OUT("Enter Amount to Deposit");
    cin>>dep;
    // balance += dep;

    return (dep);
}
void Cur_acct::checkBalance(int bal, Account& acc)
{
    double balance;
    balance = acc.getBalance();
    if (balance < minBalance)
    {
        OUT("Your Account Balance is Overdrawn")
        balance -= serviceCharge;
    }
    
}
Cur_acct::~Cur_acct()
{
}

class Sav_acct : public Account
{
public:
    Sav_acct(string name, int number, double initial_balance) : Account() {}

int compute_interest(Account& bcc) 
    {
        double Balance = getBalance();
        double interest_rate = 0.10;
        double interest = Balance * interest_rate;
        // Balance += interest;
        
        return (interest);
    }

};

void bankingServices(Account *accArr, int& numOfAccounts);
int main(void)
{
    Account *mem = new Account[100];
    int numOfAccounts = 0;
    bankingServices(mem, numOfAccounts);


    return (0);
}

void bankingServices(Account *accArr, int& numOfAccounts)
{
    int service;
    cout<<"1. New Customer"<<endl
        <<"2. Deposit"<<endl
        <<"3. Withdraw"<<endl
        <<"4. Check Balance"<<endl
        <<"5. List Customers"<<endl
        <<"6. Delete Customer"<<endl
        <<"7. Update Customer Details"<<endl
        <<"8. Exit"<<endl;
    cin>>service;

    switch (service)
    {
        case 1: 
        {
            // Create new account
            Account *acc = new Account();
            bool success = acc->Account_Details(accArr, numOfAccounts);
            if (success)
            { 
                accArr[numOfAccounts] = *acc;
                numOfAccounts++;

                // Save account details to file
                ofstream outfile("accounts.txt", ios::app);
                if (!outfile.is_open())
                {
                    cerr << "Error: Unable to open file for writing!" << endl;
                    return;
                }
                outfile << "Customer Name: " <<acc->getCustomerName() << endl 
                        << "Account Type: " << acc->getAccountType() << endl
                        << "Account Number: " << acc->getAccountNumber() << endl 
                        << "Account Balance: " <<  acc->getBalance() << endl
                        << endl
                        << endl;
                outfile.close();
            }
            else
            {
                OUT("Failed to create account due to duplicate account number.");
            }
            break;
        }
        case 2:
        {
            // Deposit
            int accNo;
            bool found = false;
            OUT("Enter Account Number:");
            cin >> accNo;
            for (int i = 0; i < numOfAccounts; i++) 
            {
                if (accArr[i].getAccountNumber() == accNo) 
                {
                    Cur_acct cur_acct;
                    int depAmt = cur_acct.deposit(accArr[i]);
                    found = true;

                    // Update account details in file
                    fstream file;
                    file.open("accounts.txt", ios::in | ios::out);
                    if (file) {
                        string line;
                        int pos = 0;
                        while (getline(file, line)) {
                            if (line.find("Account Number: " + to_string(accNo)) != string::npos)
                            {
                                pos = file.tellp();
                                file.seekp(pos - line.length());
                                file << "Account Balance: " << accArr[i].getBalance() << endl;
                                break;
                            }
                        }
                        file.close();
                    }
                    else {
                        cerr << "Error: Unable to open file for updating account details!" << endl;
                    }

                    OUT("Deposit Successful. Current Balance: " << accArr[i].getBalance());
                    break;
                }
                if (accArr[i].getAccountType() == "Saving Account") 
                {
                    Sav_acct *sav_acct;
                    int Amount = sav_acct->compute_interest(accArr[i]);
                    found = true;

                    // Update account details in file
                    fstream file;
                    file.open("accounts.txt", ios::in | ios::out);
                    if (file) {
                        string line;
                        int pos = 0;
                        while (getline(file, line)) {
                            if (line.find("Account Number: " + to_string(accNo)) != string::npos) {
                                pos = file.tellp();
                                file.seekp(pos - line.length());
                                file << "Account Balance: " << Amount << endl;
                                break;
                            }
                        }
                        file.close();
                    }
                    else {
                        cerr << "Error: Unable to open file for updating account details!" << endl;
                    }

                    OUT("Deposit Successful. Current Balance: " << accArr[i].getBalance());
                    break;
                }
            
                if (!found) 
                {
                    OUT("Account not found!");
                }
                break;
                
            } 
        }   
        case 3:
        {    
            // Withdraw
            int accNo;
            bool found = false;
            OUT("Enter Account Number:");
            cin >> accNo;
            for (int i = 0; i < numOfAccounts; i++)
            {
                if (accArr[i].getAccountNumber() == accNo)
                {
                    int withAmt;
                    OUT("Enter Amount to Withdraw:");
                    cin >> withAmt;
                    
                    if (withAmt > accArr[i].getBalance())
                    {
                        OUT("Insufficient balance!");
                    }
                
                    else 
                    {   
                        double amnt = accArr[i].getBalance();
                        amnt -= withAmt;
                        found = true;
                        // Update account details in file
                            fstream file;
                            file.open("accounts.txt", ios::in | ios::out);
                            if (file)
                            {
                                string line;
                                int pos = 0;
                                while (getline(file, line)) 
                                {
                                    if (line.find("Account Number: " + to_string(accNo)) != string::npos)
                                    {
                                        pos = file.tellp();
                                        file.seekp(pos - line.length());
                                        file << "Account Balance: " << amnt << endl;
                                        break;
                                    }
                                }
                            }
                   else 
                    {
                        cerr << "Error: Unable to open file for writing!" << endl;
                    }
                    file.close();
                    OUT("Withdrawal Successful. Current Balance: " << accArr[i].getBalance());
                    }
                }
            }
            if (!found)
            {
                OUT("Account not found!");
            }
            break;
        }

        case 4:
        {
            // Check Balance
            int accNo;
            bool found = false;
            OUT("Enter Account Number:");
            cin >> accNo;
            for (int i = 0; i < numOfAccounts; i++)
            {
                if (accArr[i].getAccountNumber() == accNo)
                {
                    found = true;
                    // Cur_acct *cur_acct;
                    // cur_acct->checkBalance(accArr[i].getBalance(), accArr[i]);
                    OUT("Account Balance: " << accArr[i].getBalance());
                }
            }
            if (!found) 
            {
                OUT("Account not found!");
            }
            break;
        }
        case 5:
        {
            // List Customers
            ifstream infile("accounts.txt");
            if (!infile.is_open()) {
                cerr << "Error: Unable to open file for reading!" << endl;
                return;
            }
            string line;
            while (getline(infile, line)) {
                OUT(line);
            }
            infile.close();
            break;
        }
        case 6:
        {    
            // Delete customer
            int accNo;
            bool found = false;
            OUT("Enter Account Number:");
            cin >> accNo;

            for (int i = 0; i < numOfAccounts; i++)
            {
                if (accArr[i].getAccountNumber() == accNo)
                {
                    found = true;

                    // Remove account details from file
                    ifstream infile("accounts.txt");
                    ofstream outfile("temp.txt");
                    if (!infile.is_open() || !outfile.is_open())
                    {
                        cerr << "Error: Unable to open files for reading and writing!" << endl;
                        return;
                    }

                    string line;
                    while (getline(infile, line))
                    {
                        if (line.find("Account Number: " + to_string(accNo)) != string::npos)
                        {
                            // Skip over the account details to be deleted
                            getline(infile, line);
                            getline(infile, line);
                            getline(infile, line);
                            continue;
                        }

                        outfile << line << endl;
                    }

                    infile.close();
                    outfile.close();

                    // Replace accounts.txt with temp.txt
                    remove("accounts.txt");
                    rename("temp.txt", "accounts.txt");

                    // Remove account from memory
                    for (int j = i; j < numOfAccounts - 1; j++)
                    {
                        accArr[j] = accArr[j + 1];
                    }
                    numOfAccounts--;

                    OUT("Account deleted successfully.");
                    break;
                }
            }
            if (!found)
            {
                OUT("Account not found.");
            }
            break;
        }
        case 7:
        {
            
            // Update customer details
            int accNo;
            bool found = false;
            OUT("Enter Account Number:");
            cin >> accNo;
            for (int i = 0; i < numOfAccounts; i++) 
            {
                if (accArr[i].getAccountNumber() == accNo) 
                {
                    found = true;
                    // Update customer name
                    OUT("Enter new Customer Name:");
                    string name;
                    cin >> name;
                    accArr[i].getCustomerName() = name;

                    // Update account type
                    OUT("Enter new Account Type:");
                    string type;
                    cin >> type;
                    if (type == "Savings Account") 
                    {
                        accArr[i].getAccountType() = type;
                        // Create new instance of savings account and copy balance
                        Sav_acct *sav_acct;
                        // sav_acct->getBalance(accArr[i].getBalance(), accArr[i]);
                        // accArr[i].getBalance() = sav_acct->getBalance();
                    }
                    else if (type == "Current Account") 
                    {
                        accArr[i].getAccountType() = type;
                        // Create new instance of current account and copy balance
                        Cur_acct *cur_acct;
                        // cur_acct->checkBalance(accArr[i].Balance, accArr[i]);
                        // accArr[i].Balance = cur_acct.deposit(accArr[i]);
                    }
                    else 
                    {
                        OUT("Invalid account type");
                    }

                    // Update account details in file
                    fstream file;
                    file.open("accounts.txt", ios::in | ios::out);
                    if (file) 
                    {
                        string line;
                        int pos = 0;
                        while (getline(file, line)) 
                        {
                            if (line.find("Account Number: " + to_string(accNo)) != string::npos) 
                            {
                                pos = file.tellp();
                                file.seekp(pos - line.length());
                                file << "Customer Name: " << accArr[i].getCustomerName() << endl
                                    << "Account Type: " << accArr[i].getAccountType() << endl
                                    << "Account Number: " << accArr[i].getAccountNumber() << endl
                                    << "Account Balance: " << accArr[i].getBalance() << endl
                                    << endl
                                    << endl;
                                break;
                            }
                        }
                        file.close();
                    }
                    else 
                    {
                        cerr << "Error: Unable to open file for writing!" << endl;
                    }
                    break;
                }
            }
            if (!found) 
            {
                OUT("Account not found");
            }
        
            break;
        }
        case 8:
        {    
            OUT("Exiting program...");
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
            break;
        }
    }
        
}