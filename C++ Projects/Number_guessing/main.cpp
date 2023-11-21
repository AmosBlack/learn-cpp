#include <iostream>
#include <ctime>

int main(){

    srand(time(0));

    std::cout << "****** NUMBER GUESSING ******\n";

    int num, guess, tries;
    num = rand() % 100 + 1;
    tries = 0;

    do{
        tries ++;
        std::cout << "Enter a number: ";
        std::cin >> guess;
        if( guess < num )
            std::cout << "**** HIGHER ****\n";
        else if(guess > num)
            std::cout << "**** LOWER ****\n";
        else
            std::cout << "******" << num << "******" << std::endl;
        
    }while(guess != num);

    return 0;
}   