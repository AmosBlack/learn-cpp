#include <iostream>
using namespace std;

int main(){
    int number;
    number = -1;
    //BASIC WHILE

    // while(number < 0){  
    //     cout << "Enter a number: ";
    //     cin >> number;
    // }

    //DO WHILE
    // do some code, then repeat again if condition is true 
    do{
        cout << "Enter a number: ";
        cin >> number; 
    }while(number < 0);

    cout << "The number is: " << number << endl;
}