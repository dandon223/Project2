#include"day.h"
using namespace std;

int day::findPlace(string courseName , int courseGroup, int people)
{
    string courseGroup2 = to_string(courseGroup);
    string people2 = to_string (people);
    if(first[0]=="0")
    {
        first[0] = courseName;
        first[1] = courseGroup2;
        first[2] = people2;
        return 1;
    }
    else if(second[1]=="0")
    {
        second[0] = courseName;
        second[1] = courseGroup2;
        second[2] = people2;
        return 2;
    }
    else if(third[2]=="0")
    {
        third[0] = courseName;
        third[1] = courseGroup2;
        third[2] = people2;
        return 3;
    }
    else
        return 0;
}

ostream & operator<< (ostream &exit, const day &d)
{
    exit<< endl;
    cout<<d.name<<" | "<<d.first[0]<<"|"<<d.first[1]<<"|"<<d.first[2]<<"||";
    cout<<d.second[0]<<"|"<<d.second[1]<<"|"<<d.second[2]<<"||";
    cout<<d.third[0]<<"|"<<d.third[1]<<"|"<<d.third[2]<<endl;
    return exit;


}
