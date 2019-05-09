#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<string>
#include<vector>
class day;
class course;
class interface
{
    private:
        std::vector<day> days;
        std::vector<course> courses;
        std::vector<std::string> inputs;
    public:
        friend class day;
        friend class course;
        void setup(std::string DAYS[5]);
        int readingFile(std::string filename);
        void makingCourses();
        int makingPlan();
        int testInput();
        void readInput();
        friend std::ostream & operator<< (std::ostream &exit, const interface &d );


};













#endif
