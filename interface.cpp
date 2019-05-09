#include"interface.h"
#include "day.h"
#include "course.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include <cctype>
using namespace std;

void interface::setup(string DAYS[5])
{
    for(int i =0 ; i<5;i++)
    {
        day A(DAYS[i]);
        days.push_back(A);
    }
}
/*Zczytuje z pliku i zapisuje w tablicy inputs*/
int interface::readingFile(string filename)
{
    ifstream myfile;
    myfile.open(filename);
    if (!myfile.good())
    {
        cout<<"Could not open a file!\n";
        return 1;
    }
    
    string input;
    myfile >>input;
    while(!myfile.eof())
    {
        inputs.push_back(input);
        myfile >>input;
    }
    myfile.close();
    return 0;
}
/* Rozdziela informacje z inputs na poszczegolne kursy*/
void interface::makingCourses()
{
    for(unsigned int i=0;i<inputs.size();i=i+2)
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
    for(unsigned int i=0; i<courses.size();i++)
        courses[i].show();
}
/* petla przechodzi przez kazdy kurs i znajduje dla niego odpowiednie godziny w planie*/
int interface::makingPlan()
{
    int whichCourse =0;
    for(unsigned int i=0; i < courses.size();i++)
    {
        whichCourse = i;
        unsigned int whichDayFirst = 0;
        int termin1 = 0;
        for(unsigned int k=0 ; k<days.size();k++)
        {
            termin1 = days[k].findPlace(courses[i].whatName(),courses[i].whatGroup(),courses[i].howManyPeople());
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
        for(unsigned int k= 0 ; k<days.size();k++)
        {
            if (whichCourse ==0)
            {
                termin2 = days[days.size()-1].findPlace(courses[i].whatName(),courses[i].whatGroup(),courses[i].howManyPeople());
                break;
            }
           else if (k!=whichDayFirst)
            {
                termin2 = days[k].findPlace(courses[i].whatName(),courses[i].whatGroup(),courses[i].howManyPeople());
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
    return 0;
}
/*Sprawdza poprawnie sformatowany plik*/
int interface::testInput()
{
    if(inputs.size()%2!=0)
        return 1;
    for(unsigned int i=1; i<inputs.size();i+=2)   // podwojna petla sprawdza czy zostaly wpisane liczby
    {                                    // tam gdzie powinno zostac podane liczba uczestnikow
        for(unsigned int k=0; k<inputs[i].size();k++)
        {
            if (isdigit(inputs[i][k])==0)
            {
                cout<<"Bad Input\n";
                return 1;
            }
        }
    }
    return 0;
}
void interface::readInput()
{
    cout<<"-----------------------\n";
    cout<<"        Inputs:        \n";
    for (unsigned int i=0; i<inputs.size();i++)
        cout<<inputs[i]<<endl;
}

/* wypisuje tabelke na ekran */
ostream & operator<< (ostream &exit, const interface &d)
{
    exit<<setw(12)<<"14-16";
    cout<<setw(12)<<"16-18";
    cout<<setw(12)<<"18-20"<<endl;
    for(int i=0 ; i<5 ; i++)
    {
        cout<<d.days[i];
    }
    return exit;


}













