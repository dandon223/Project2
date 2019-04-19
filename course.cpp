#include"course.h"
using namespace std;

course::course(string a,vector<course> &courses,int num)
{
    name = a;
    people=num;
    int counter=1;
    for(int i=0 ; i<courses.size();i++)
    {
        if(name ==courses[i].whatName())
            counter = counter + 1 ;
    }
    group = counter;
    
}
