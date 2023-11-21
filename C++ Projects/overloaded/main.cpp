#include <iostream>

void bakePizza();

int main()
{
    bakePizza("pepperoni", "mushroom");

    return 0;
}

void bakePizza()
{
    std::cout << "Here is your pizza\n" << std::endl;
}

void bakePizza(std::string topping1, std::string topping2) //func + parameter need to be diff, func name can be same - OVERLOADED FUNCTIONS
{
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza" << std::endl;
}