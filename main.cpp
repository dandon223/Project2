#include <iostream>
#include<vector>
#include <string>
#include<fstream>
#include "course.h"
#include"day.h"

using namespace std;

int main()
{
    vector<day> days;
    vector<course> courses;
    vector<string> inputs;
    string DAYS[5] {"Pon","Wt","Sr","Czw","Pia"};
    string v[3]={"0","0","0"};
    for(int i =0 ; i<5;i++)
    {
        day A(DAYS[i]);
        days.push_back(A);
    }
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
            return 0;
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
            return 0;
        }
    }
    cout<<days[0];
    cout<<days[1];
    cout<<days[2];
    cout<<days[3];
    cout<<days[4];
    return 0;
}
