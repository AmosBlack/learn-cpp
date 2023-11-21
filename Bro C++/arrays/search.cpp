#include<iostream>
int searchArray(int array[], int size, int element);

int main()
{
    int numbers[] = {1, 2 , 3, 4, 6, 7, 9};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    int indice, myNum;

    std::cout << "Enter an element to search for: ";
    std::cin >> myNum;

    indice = searchArray(numbers, size, myNum);

    if(indice != -1){
        std::cout  << "The indice is: " << indice << std::endl;
    }
    else{
        std::cout << "The element was not found" << std::endl;
    }

    return 0;
}

int searchArray(int array[], int size, int element){

    for(int i = 0; i < size; i++ ){
        if(element == array[i]){
            return i;
        }
    }

    return -1;
}