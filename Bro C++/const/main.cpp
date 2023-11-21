#include<iostream>
void printInfo(const std::string &name, const int &age);

int main()
{
    //const useful for references and pointers

    std::string name = "Bro";
    int age = 15;
    printInfo(name, age);

    return 0;
}

//old vs with const
void printInfo(const std::string &name,const int &age){
    // name = "lmao"; wn't work because const
    std::cout << name << " " << age << std::endl;
}

//const -> more secure