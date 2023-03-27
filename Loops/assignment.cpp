#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
#define RATE 0.16

int main()
{
    double Principle;
    double Amount;
    double Interest;
    char StudentName [255];
    char RegNo[255];
    int BankingAcc;
    float Months;
    
    cout<<"Enter Student's Name"<<endl;
    cin.getline(StudentName, 256);
    cout<<"Enter Registration Number"<<endl;
    cin>> RegNo;
    cout<<"____________________________________"<<endl;
  do
  {
    cout<<"Choose Banking Account"<<endl <<"1.Saving Account"<<endl <<"2.Fixed deposit Account"<<endl;
    cin>> BankingAcc;
    

      if (BankingAcc == 1)
    {
        cout<<"Enter Principle (Deposited Amount): ";
        cin>> Principle;
        cout<<"Enter Time in Months: ";
        cin>> Months;
        float Time = Months/12;
        
        Interest = Principle * RATE * Time;
        Amount = Principle + Interest;
    
        break;
    }
    
    else if (BankingAcc == 2)
    {
        cout<<"Enter Principle (Deposited Amount): ";
        cin>> Principle;
        cout<<"Enter Time in Months: ";
        cin>> Months;
        float Time = Months/12;
        
        Amount= Principle * (pow((1+RATE),Time));
        Interest= Amount - Principle;

        break;
    }
    else
    {
        cout<<endl;
        cout<<"Invalid Choice!"<<endl;
    }
  } while (BankingAcc != 1 || BankingAcc != 2);

        cout<<endl;
        cout<< "The Principle is: "<<Principle<<endl;
        cout<< "The Interest earned is: "<<Interest<<endl;
        cout<< "Total Acquired Amount is: "<<Amount<<endl;
        cout<<endl;

        getch();

return 0;
}