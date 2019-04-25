#include"interface.h"
#include "day.h"
#include "course.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void interface::setup(string DAYS[5])
{
    for(int i =0 ; i<5;i++)
    {
        day A(DAYS[i]);
        days.push_back(A);
    }
}

void interface::readingFile()
{
    ifstream myfile;
    myfile.open("text.txt");
    string input;
    myfile >>input;
    while(!myfile.eof())
    {
        inputs.push_back(input);
        myfile>>input;
    }
    myfile.close();
    
    for(int i=0; i<inputs.size();i++)
        cout<<inputs[i]<<endl;
}

void interface::makingCourses()
{
    for(int i=0;i<inputs.size();i=i+2)
    {
        int number = stoi(inputs[i+1]);
        while(number!=0)
        {
            if(number>=10)
            {
                course A(inputs[i],courses,10);
                courses.push_back(A);
                number = number - 10;
            }
            else if(number>0&&number<10)
            {
                course A(inputs[i],courses,number);
                courses.push_back(A);
                number = 0;
            }
            inputs[i+1] = number;
        }
    }
    for(int i=0; i<courses.size();i++)
        courses[i].show();
}

int interface::makingPlan()
{
    for(int i=0; i < courses.size();i++)
    {
        int whichDayFirst = 0;
        int termin1 = 0;
        for(int k=0 ; k<days.size();k++)
        {
            termin1 = days[k].findPlace(courses[i].whatName(),courses[i].whatGroup(),courses[i].whatPeople());
            if (termin1==1 || termin1==2 || termin1==3)
            {
                whichDayFirst = k;
                break;
            }
        }
        if(termin1==0)
        {
            cout<<" There is not enough place!!!\n";
            return 2;
        }
        int termin2=0;
        for(int k=0 ; k<days.size();k++)
        {
            if (k!=whichDayFirst)
            {
                termin2 = days[k].findPlace(courses[i].whatName(),courses[i].whatGroup(),courses[i].whatPeople());
                if (termin2==1 || termin2==2 || termin2==3)
                {
                    break;
                }
            }
        }
        if(termin2==0)
        {
            cout<<"There is not enough place!!!\n";
            return 2;
        }
    }
}

ostream & operator<< (ostream &exit, const interface &d)
{
    exit;
    cout<<setw(12)<<"14-16";
    cout<<setw(12)<<"16-18";
    cout<<setw(12)<<"18-20"<<endl;
    for(int i=0 ; i<5 ; i++)
    {
        cout<<d.days[i];
    }
    return exit;


}












