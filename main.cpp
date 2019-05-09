#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include<fstream>
#include "course.h"
#include"day.h"
#include "interface.h"
int runTest(void);

using namespace std;

int main()
{
    char answer;
    cout<<"Do you want to run a test? y/n\n";
    cin >> answer;
    if (answer =='y'|| answer =='Y')
        runTest();
    string DAYS[5] {"Pon","Wt","Sr","Czw","Pia"};
    interface Interface;
    Interface.setup(DAYS);
    int FileOpened = Interface.readingFile("text.txt");
    int BadInput = Interface.testInput();
    if (BadInput||FileOpened)
        return 0;
    Interface.makingCourses();
    int Possible = Interface.makingPlan();
    if(Possible==2)
        return 0;
    cout<<Interface;
    return 0;
}

int runTest(void)
{
    string TESTING[4] ={"A1","15","A3","12"};
    ofstream myfile;
    myfile.open("Test.txt", fstream::out);
    for(int i =0; i<4;i++)
    {
        myfile << TESTING[i]<<" ";
    }
    myfile.close();
    string DAYS[5] {"Pon","Wt","Sr","Czw","Pia"};
    interface Interface;
    Interface.setup(DAYS);
    int FileOpened = Interface.readingFile("Test.txt");
    int BadInput = Interface.testInput();
    if (BadInput||FileOpened)
    {
        cout<<"END OF TEST\n";
        return 0;
    }
    Interface.readInput();
    cout<<"-----------------\n";
    cout<<"And now courses\n";
    Interface.makingCourses();
    cout<<"                  \n";
    cout<<"And now table\n";
    int Possible = Interface.makingPlan();
    if(Possible==2)
        return 0;
    cout<<Interface;
    cout<<"    END OF TEST\n";
    cout<<"------------------\n";
    cout<< "BEGINING PROGRAMME\n";
    return 0;
}
