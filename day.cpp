#include"day.h"
#include<iomanip>
using namespace std;
/*Wypelnia wolna godzine danymi kursu, jak nie znajdzie zwraca 0 */
int day::findPlace(string courseName , int courseGroup, int howManyPeople)
{
    string courseGroup2 = to_string(courseGroup);
    string tempPeople = to_string (howManyPeople);
    if(firstLesson[0]=="-")
    {
        firstLesson[0] = courseName;
        firstLesson[1] = courseGroup2;
        firstLesson[2] = tempPeople;
        return 1;
    }
    else if(secondLesson[1]=="-")
    {
        secondLesson[0] = courseName;
        secondLesson[1] = courseGroup2;
        secondLesson[2] = tempPeople;
        return 2;
    }
    else if(thirdLesson[2]=="-")
    {
        thirdLesson[0] = courseName;
        thirdLesson[1] = courseGroup2;
        thirdLesson[2] = tempPeople;
        return 3;
    }
    else
        return 0;
}
/*Wypisuje dzien w forme wiersza w tabelce*/
ostream & operator<< (ostream &exit, const day &d)
{
    exit;
    cout<<setw(3)<<d.name<<" | "<<setw(4)<<d.firstLesson[0]<<"."<<d.firstLesson[1]<<"|"<<setw(3)<<d.firstLesson[2]<<"||";
    cout<<setw(3)<<d.secondLesson[0]<<"."<<d.secondLesson[1]<<"|"<<setw(3)<<d.secondLesson[2]<<"||";
    cout<<setw(3)<<d.thirdLesson[0]<<"."<<d.thirdLesson[1]<<"|"<<setw(3)<<d.thirdLesson[2]<<endl;
    return exit;


}
