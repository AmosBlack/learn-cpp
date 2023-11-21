#include<iostream>

class Human{
    public:
        std::string name;
        std::string occupation;
        int age;
        bool employed = false;
        bool gay = false;

        void eat(){
            std::cout << name << " is eating\n";
        }

        void drink(){
            std::cout << name << " is drinking\n";
        }

        void sleep(){
            std::cout << name << " is sleeping\n";
        }

};


int main(){
    //object - collection of attri and methods
    //       -attributes are properties, methods are functions
    //       - created from class which acts as a  blueprint

    Human human1;
    human1.name = "EGG";
    human1.occupation = "C++ Femboy";
    human1.age = 2;

    std::cout << human1.name << '\n';
    human1.eat();

    return 0;   
}