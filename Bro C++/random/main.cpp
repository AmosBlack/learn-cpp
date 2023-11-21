#include <iostream>
#include <ctime>

int main(){
    //not truly random

    srand(time(NULL)); //seed, generally time

    int num = (rand() % 20) + 1;

    std::cout << num << std::endl;

    return 0;

}