#include <iostream>

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);
/*
Luhn Algorithm

1. Double every second digit from right to left
   If doubled number is 2 digits, split
2. Add all single digits from step1
3. Add all odd numbered digits from right to left
4. Sum results from steps 2,3
5. If sum divisible by 10, # is valid
*/

int main(){

    std::string cardNumber;
    int result = 0;

    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber <<  " is valid!";
    }
    else{
        std::cout << cardNumber << " is not valid!";
    }

    return 0;
}

int getDigit(const int number){
    return number % 10 + (number/10 % 10); //1st place and 10s place
}

int sumOddDigits(const std::string cardNumber){
    int sum{0};

    for(int i = cardNumber.size() - 1; i >= 0; i-=2){
        sum += cardNumber[i] - '0'; // '0' = 48 in ASCII
    }
    return sum;
}

int sumEvenDigits(const std::string cardNumber){
    int sum{0};

    for(int i = cardNumber.size() - 2; i >= 0; i-=2){
        sum+= getDigit((cardNumber[i] - '0') * 2); // '0' = 48 in ASCII
    }

    return sum;
}