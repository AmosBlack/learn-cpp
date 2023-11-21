#include<iostream>

int main()
{
    std::string name = "Amos";
    int age = 14;
    bool student = true;

    std::cout << &name << "\n" << &age << "\n" << &student << "\n";

    //bools-1byte;int-4bytes;

    return 0;
}