#include<iostream>
//struct stores related variables

struct student{
    std::string name;
    double gpa;
    bool enrolled = true; //default value
};

int main()
{
    student student1;
    student1.name = "spongebob";
    student1.gpa = 3.8;

    std::cout << student1.name << " " << student1.gpa << " " << student1.enrolled << std::endl; 

    return 0;
}