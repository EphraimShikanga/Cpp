#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>

using namespace std;

#define CLASS 10
#define a 80
#define b 70
#define c 60
#define d 50
#define e 40




typedef struct
{
    string regNo;
    string firstname;
    string surname;
    string address;
    string courseId;
    int No_of_Units;
    char **unitsRegistered;
    int *unitsMarks;

}studentDetails;

int *getMarks(int units);
char **getUnits(int units);
void getData(studentDetails *stdl);
float computetotalMarks(studentDetails *stdl);
float computeMean(studentDetails *stdl);
float computeClassMean(studentDetails stdl[]);
float computeSTDDEV(studentDetails stdl[]);
char computeGrade(studentDetails *stdl);
int highestMark(studentDetails stdl[]);
int lowestMark(studentDetails stdl[]);
void printData(studentDetails stdl[]);



int main(void)
{
    
    studentDetails Students[CLASS];


    for (int  i = 0; i < CLASS; i++)
    {
        cout<<endl;
        cout<<endl;
        cout<<"FILL STUDENT "<< i+1 <<" DETAILS"<<endl;
        cout<<endl;
        getData(&Students[i]);
    }


    printData(Students);

    getch();
    
return (0);
}

int *getMarks(int units)
{
    int *Marks = new int[units];

    cout<<"____________________________________________"<<endl;
    cout<<"     MARKS       "<<endl;
    cout<<endl;
    for (int i = 0; i < units; i++)
        {
            cout<<"Enter Marks for Unit "<<i+1<<": ";
            cin>>*(Marks+i);
        }

return (Marks);
}

char **getUnits(int units)
{
    char **Units = new char*[units];

    cout<<"______________________________________________"<<endl;
    cout<<"     UNITS   "<<endl;
    cout<<endl;

    for (int i =0; i < units; i++)
    {
        Units[i] = new char[50];
        cout<<"Enter Unit "<<i+1<<": ";
        cin>>Units[i];
    }
return (Units);
}

void getData(studentDetails *stdl)
{
    cout<<"Enter Registration Number: ";
    cin>>stdl->regNo;

    cout<<"Enter Firstname: ";
    cin>>stdl->firstname;

    cout<<"Enter Surname: ";
    cin>>stdl->surname;

    cout<<"Enter Address: ";
    cin>>stdl->address;

    cout<<"Enter CourseId: ";
    cin>>stdl->courseId;

    cout<<"Enter Number of Units: ";
    cin>>stdl->No_of_Units;

    stdl->unitsRegistered = getUnits(stdl->No_of_Units);
    stdl->unitsMarks = getMarks(stdl->No_of_Units);

}

float computetotalMarks(studentDetails *stdl)
{
    int totalMarks = 0;
    for (int i = 0; i < stdl->No_of_Units; i++)
        {
            totalMarks = totalMarks + stdl->unitsMarks[i];
        }

return totalMarks;
}

float computeMean(studentDetails *stdl)
{
    float StudentsMean;
    float marks = computetotalMarks(stdl);
    StudentsMean = (marks / stdl->No_of_Units);

return StudentsMean;
}

float computeClassMean(studentDetails stdl[])
{
    float ClassMarks = 0;
    float ClassMean;
    for (int i = 0; i < CLASS; i++)
    {
        float meanFrom = computeMean(&stdl[i]);
        ClassMarks += meanFrom;
    }
    
    ClassMean = (ClassMarks / CLASS);

return ClassMean;
}

float computeSTDDEV(studentDetails stdl[])
{
    float dev;
    float variance;
    float STDDEV;
    float AbsMean;
    float Sumdev = 0;
    float classMean = computeClassMean(stdl);

    for (int i = 0; i < CLASS; i++)
        {
            float meanFrom = computeMean(&stdl[i]);
            AbsMean = meanFrom - classMean;
            dev = pow(AbsMean,2);
            Sumdev += dev;
        }

    variance = (Sumdev / CLASS);
    STDDEV = sqrt(variance);

return STDDEV;
}

int highestMark(studentDetails stdl[])
{
    int HighestClassMark;

    if (stdl[0].unitsMarks[0] > 0)
    {
        HighestClassMark = stdl[0].unitsMarks[0];
    } 
    else 
        {
            // where the first studentDetails object has no unit marks
        return 0;
        }
    for (int i = 0; i < CLASS; i++)
    {
        for (int j = 0; j < stdl->No_of_Units; j++)
        {
            if (HighestClassMark < stdl[i].unitsMarks[j])
            {
                HighestClassMark = stdl[i].unitsMarks[j];
            }
            
        }
        
    }
    return HighestClassMark;
}

int lowestMark(studentDetails stdl[])
{
    int LowestClassMark;
    if (stdl[0].unitsMarks[0] > 0)
    {
        LowestClassMark = stdl[0].unitsMarks[0];
    } 
    else 
    {
            // where the first studentDetails object has no unit marks
        return 0;
    }
    for (int i = 0; i < CLASS; i++)
    {
        for (int j = 0; j < stdl->No_of_Units; j++)
        {
            if (LowestClassMark > stdl[i].unitsMarks[j])
            {
                LowestClassMark = stdl[i].unitsMarks[j];
            }
            
        }
        
    }
return LowestClassMark;
}

char computeGrade(studentDetails *stdl)
{
    char Grade;
    float Mean = computeMean(stdl);
    if (Mean >= a)
        {
            return 'A';
        }
    if (Mean >= b)
        {
            return 'B';
        }
    if (Mean >= c)
        {
            return 'C';
        }
    if (Mean >= d)
        {
            return 'D';
        }
    if (Mean >= e)
        {
            return 'E';
        }
    else
        {
            return 'F';
        }
}

void printData(studentDetails stdl[])
{
    cout<<endl;
    for (int i = 0; i < CLASS; i++)
    {
        cout<<endl;
        cout<<"STUDENT "<< i+1<<endl;
        cout<<endl;
        cout<<"Name: "<<stdl[i].firstname +" "+stdl[i].surname<<endl;
        cout<<"Registration Number"<<stdl[i].regNo<<endl;
        cout<<"Address: "<<stdl[i].address<<endl;
        cout<<"Course ID: "<<stdl[i].courseId<<endl;
        cout<<"Units Registered: "<<stdl[i].No_of_Units<<endl;
        cout<<endl;
        cout<<"Units & Marks"<<endl;
        for (int j = 0; j < stdl[i].No_of_Units; j++)
            {
                cout<<stdl[i].unitsRegistered[j]<<" "<<stdl[i].unitsMarks[j]<<endl;
            }
        cout<<endl;    
        cout<<"TOTAL MARKS: "<<computetotalMarks(&stdl[i])<<endl;
        cout<<"MEAN MARK: "<<computeMean(&stdl[i])<<endl;
        cout<<"GRADE: "<<computeGrade(&stdl[i])<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"     CLASS RESULTS"<<endl;
    cout<<endl;
    cout<<"Highest Mark in Class: "<<highestMark(stdl)<<endl;
    cout<<"Lowest Mark in Class: "<<lowestMark(stdl)<<endl;
    cout<<"CLASS MEAN: "<<computeClassMean(stdl)<<endl;
    cout<<"STANDARD DEVIATION: "<<computeSTDDEV(stdl)<<endl;
}