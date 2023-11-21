#include<iostream>

int main()
{

    //add memory in heap rather than stack
    char *pgrades = NULL;
    int size;

    std::cout << "grade #: ";
    std::cin >> size;

    pgrades = new char[size];

    for(int i = 0; i < size; i++){
        std::cout << "Enter grade #" << i+1 << ": ";
        std::cin >>pgrades[i];
    }

    for(int i=0; i < size; i++){
        std::cout << pgrades[i] << " ";
    }

    std::cout << std::endl;

    delete[] pgrades;

    return 0;
}