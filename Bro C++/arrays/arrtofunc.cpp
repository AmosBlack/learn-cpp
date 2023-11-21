#include<iostream>
double getTotal(double prices[], int size);

int main(){
    double prices[] = {15, 25, 35, 47};
    int size = sizeof(prices)/sizeof(double);

    std::cout << getTotal(prices, size) << "\n";

    return 0;
}

double getTotal(double prices[], int size){
    double total = 0;
    
    for(int i = 0; i < size; i++){
        total += prices[i];
    }

    return total;
}