#include<iostream>


struct Car{
    std::string model;
    std::string color;
    int year;
    bool working = true;
};

void printCar(Car &car);
void paintCar(Car &car);

int main()
{
    Car car1;
    car1.model = "Tesla Model Y";
    car1.year = 2023;
    car1.color = "White";

    Car car2;
    car2.model = "Mclaren P1";
    car2.year = 2016;
    car2.color = "Black";
    std::cout << &car2 << "\n";
    printCar(car2);

    return 0;
}

void printCar(Car car){ //by default pass by value
    std::cout << &car << "\n";
    std::cout << "Car: " << car.model << "\nYear: " << car.year << "\nColour: " << car.color << std::endl;
}

void paintCar(Car &car){

}