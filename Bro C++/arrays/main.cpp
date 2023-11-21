#include <iostream>

int main(){

    std::string car[] = {"Corvette", "Camry", "Mustang"};
    
    car[0] = "Charger";

    std::cout << car[0];
    
    return 0;
}