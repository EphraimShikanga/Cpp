#include <iostream>
#include <conio.h>
using namespace std;
#define SURCHARGE 1.15
#define MinCharged 50
#define THRESHOLD 300

float units;
float getCharges();
int main (void)
{
    
    char name[255];
    
    cout<<"Enter your name: ";
    cin.getline(name,255 );
    cout<<"Enter Number of Units: ";
    cin>>units;
    
    cout<<""<<endl;
    cout<<"_______________________________________________"<<endl;
    cout<<"User's Name: "<<name<<endl;
    cout<<"Number of Units: "<<units<<endl;
    cout<<"Total Charges: "<<getCharges()<<endl;
    cout<<"________________________________________________"<<endl;
    cout<<""<<endl;

    getch();


    
    return 0;
}

float getCharges()
{
    
    float charges;
    
    if (units == 0)
    {
        charges = MinCharged;
    }
    else if (units <= 100)
    {
        charges = units * 60;
    }
    else if(units > 100 )
    {
        charges = (100*60) + ((units -100)*80);
    }
    else if(units > 300)
    {
        charges = (100 * 60) + ((units - 100) * 80) + ((units - 200) * 90);
    }

    if (charges < MinCharged)
    {
        charges = 50;
    }
    
    
    if (charges > THRESHOLD)
        charges = charges * SURCHARGE;
    

    return (charges);
}

