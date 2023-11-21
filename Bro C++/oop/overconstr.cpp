#include<iostream>

class Pizza{
    public:
        std::string topping1;   
        std::string topping2;

    Pizza(std::string topping1){
        this->topping1 = topping1;
    }

    Pizza(std::string topping1, std::string topping2){
        this-> topping1 = topping1;
        this-> topping2 = topping2;
    }

    void topping(){
        std::cout << topping1 << "\n";
    }
};

int main()
{
    //overloaded constructors ->allow different number of parameters when instantiating objects
    Pizza pizza1("mushroom", "pepperoni");
    Pizza pizza2("olives");

    pizza1.topping();
    pizza2.topping();

    return 0;
}