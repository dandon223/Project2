#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
#include<vector>
class interface;
class course
{
    private:
        std::string name;
        int group;
        int participants;
    public:
        friend class interface;
        course(std::string a,std::vector<course> &courses,int num);
        std::string whatName(){return name;}
        void show(){std::cout<<name<<"."<<group<<" | "<<participants<<std::endl;}
        int whatGroup(){return group;}
        int howManyPeople(){return participants;}
        

};



#endif
