#include<iostream>
using namespace std;

int main()
{
    string cars[][3]  = {
        {"Mustang", "Charger", "Corvette"},
        {"Cadillac", "Buick", "Soul"},
        {"Camaro", "F-150", "Challenger"}
    };

    int rows = sizeof(cars)/sizeof(cars[0]);
    int columns = sizeof(cars[0])/sizeof(cars[0][0]);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << cars[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}