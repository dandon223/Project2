#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
#include<vector>
class course
{
    private:
        std::string name;
        int group;
        int people;
        std::string termin_1[2]={"0","0"};
        std::string termin_2[2]={"0","0"};
    public:
        course(std::string a,std::vector<course> &courses,int num);
        std::string whatName(){return name;}
        void show(){std::cout<<name<<","<<group<<","<<people<<std::endl;}
        int whatGroup(){return group;}
        int whatPeople(){return people;}
        

};



#endif
