#include<iostream>

void walk(int steps);

int main()
{
    //recursion -> program invokes itself -> good for sorting and searching -> more memory, slower speed -> less and cleaner code;
    int steps;
    std::cin >> steps;
    walk(steps);
    return 0;
}

void walk(int steps){
    //iterative
    for(int i=0; i < steps; i++){
        std::cout << "Step #" << i + 1 << "\n";
    }
    // //recursive
    // if(steps > 0){
    //     std::cout << "You took a step";
    //     walk(steps-1);
    // }
}