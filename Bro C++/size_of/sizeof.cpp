#include<iostream>
int main()
{
    //sizeof() = determines size in bytes
    
    double gpa = 2;    

    std::cout << sizeof(double) << " bytes\n";
    std::cout << sizeof(gpa) << " bytes\n";

    // finding sizeof an array
    char grades[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::cout << sizeof(grades) << " bytes\n";
    std::cout << sizeof(grades)/sizeof(char) << " elements" << std::endl;
    
    return 0;
}