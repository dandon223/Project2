#include <iostream>
#include<vector>
#include <string>
#include<fstream>
#include "course.h"
#include"day.h"
#include "interface.h"

using namespace std;

int main()
{
    string DAYS[5] {"Pon","Wt","Sr","Czw","Pia"};
    interface Interface;
    Interface.setup(DAYS);
    Interface.readingFile();
    Interface.makingCourses();
    int Possible = Interface.makingPlan();
    if(Possible==2)
        return 0;
    cout<<Interface;
    return 0;
}
