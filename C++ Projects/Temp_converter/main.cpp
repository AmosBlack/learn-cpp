#include <iostream>

//temp converter between C and F

int main(){
    char temp_unit;
    double temp;

    std::cout << "***** Temperature Conversion *****\n";
    std::cout << " F = Fahrenheit \n";
    std::cout << " C = Celcius \n";
    std::cout << "What unit would you like to convert to: ";
    std::cin >> temp_unit;
    std::cout << temp_unit << std::endl;

    if(temp_unit == 'F' || temp_unit == 'f'){
        std::cout << "Enter the temperature in Celcius: ";
        std::cin >> temp;
        //conversion
        temp = (9/5)*temp + 32;
        std::cout << "The temperature is: " << temp << "F";
    }

    else if(temp_unit = 'C' || temp_unit == 'c'){
        std::cout << "Enter the temperature in Fahrenheit: ";
        std::cin >> temp;
        temp = (temp-33)*5/9;
        std::cout << "The temperature is: " << temp << "C\n";
    }
    else{
        
    }

    std::cout << "**********************************" << std::endl;

    return 0;

}