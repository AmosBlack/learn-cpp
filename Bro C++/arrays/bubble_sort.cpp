#include<iostream>

void sort(int array[], int size);

int main()
{
    int array[] = {10, 43, 2, 15,  151, 356,  472 ,39, 7};
    int size = sizeof(array)/sizeof(int);

    sort(array, size);

    for(int element : array){
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

void sort(int array[], int size){
    int temp;
    
    for(int i = 0; i < size - 1; i++){ //larger values will gravitate towards end, so (size-1)
        for(int j = 0; j < size - i - 1; j++){ // don't sort elements already sorted, so (size-i-1)
            if(array[j] < array[j+1]){ // the '>' and '<' are for ascending and descending
                //swap values
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}