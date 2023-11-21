#include<iostream>

int main()
{
    std::string pizzas[5] = { "pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    // std::string *ppizzas = &pizzas; //error coz already a pointer
    
    std::cout << *(pizzas + 1) << '\n';

    return 0;
}