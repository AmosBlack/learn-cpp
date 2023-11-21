#include <iostream>
#include <ctime>

int main(){

    srand(time(0));
    int randNum = rand() % 3 + 1;

    switch(randNum){
        case 1:
            std::cout << "You won a bumper sticker!" << std::endl;
            break;
        case 2:
            std::cout << "You won a t-shirt" << std::endl;
            break;
        case 3:
            std::cout << "You won concert tickets" << std::endl;
    }


    return 0;
}