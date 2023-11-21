#include<iostream>

enum Day {sunday = 0, monday = 1, tuesday = 2, saturday = 6, wednesday = 3, thursday = 4, friday = 5};
//if you dont assign values, automatic values will be assigned

int main()
{
    //enums -> paired name-integer constants -> for potential options -> customdata type

    Day today = monday;

    switch(today){
        case sunday: //use name
            std::cout << "It's a weekend";
            break;
        case 6: //use integer
            std::cout << "It's a weekend";
            break;
        default:
            std::cout << "It's a weekend";
            break;
    };

    std::cout << std::endl;

    return 0;
}