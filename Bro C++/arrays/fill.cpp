#include<iostream>

int main()
{
    // //MANUAL
    // std::string foods[10] = { "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza" };
    //FILL
    const int size = 350;
    std::string foods[size]; 

    fill(foods, foods+(size/3), "Pakeezah");
    fill(foods+(size/3), foods+size, "Motichoor Ladoo");

    for(std::string food : foods){
            std::cout << food << " ";
    }

    std::cout << std::endl;

    return 0;
}