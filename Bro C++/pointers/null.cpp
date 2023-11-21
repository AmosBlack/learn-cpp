#include<iostream>

int main()
{
    //null => value to tell not a value
    //nullptr = keyword that represents a null pointer liter
    //for eg to determine if address was succesfully assigned an address

    int *pointer = nullptr;
    int age = 15;

    pointer = &age;
    
    //how to check if address is assigned, useful when playing with dynamic memory
    if(pointer != nullptr){
        std::cout << *pointer;
    } 
    else{
        std::cout << "address wasnt assigned";
    }

    return 0;
}