#include<iostream>

class Student{
    public:
        std::string name;
        int age;
        double gpa;
    //constructor
    Student(std::string name, int age, double score){
        this->name = name;
        this->age = age; //this-> prefi* is necessary only for same variables 
        gpa = score;
    }

};

int main()
{
    //constructor -> special method automatically called when object instantiated
    //            -> useful for assigning values to attribute as arguments
    Student student1("AmosBlack", 14, 3.6);
    std::cout << student1.age << std::endl;
    return 0;
}