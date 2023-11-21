#include<iostream>

int main()
{
    std::string name = "Bro";
    std::string *pname = &name;

    int age = 21;
    int *page = &age;

    std::cout << pname << " " << *pname << "\n";
    std::cout << page << " " << *page << "\n";

    return 0;
}