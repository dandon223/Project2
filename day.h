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
        std::string first[3]={"0","0","0"};
        std::string second[3]={"0","0","0"};
        std::string third[3]={"0","0","0"};
    public:
        friend class interface;
        day(std::string x){name=x;}
        void show(){std::cout<<name<<" "<<first[2]<<std::endl;}
        int findPlace(std::string courseName , int courseGroup, int people);
        friend std::ostream & operator<< (std::ostream &exit, const day &d );
};



#endif
