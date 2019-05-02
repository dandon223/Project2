#ifndef DAY_H
#define DAY_H
#include<iostream>
#include<string>
#include<vector>
class interface;
class day
{
    private:
        std::string name;
        std::string firstLesson[3]={"-","-","-"};
        std::string secondLesson[3]={"-","-","-"};
        std::string thirdLesson[3]={"-","-","-"};
    public:
        friend class interface;
        day(std::string x){name=x;}
        void show(){std::cout<<name<<" "<<firstLesson[2]<<std::endl;}
        int findPlace(std::string courseName , int courseGroup, int people);
        friend std::ostream & operator<< (std::ostream &exit, const day &d );
};



#endif
