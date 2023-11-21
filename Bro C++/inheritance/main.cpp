#include<iostream>

class Animal{
    public:
        bool alive = true;
    void eat(){
        std::cout << "This animal is eating\n";
    }
};

class Dog : public Animal{
    public:

    void bark(){
        std::cout << "Woof!\n";
    }

    void eat(){
        std::cout << "NOM NOM NOM\n";
    }

};

class Cat : public Animal{
    public:

    void meow(){
        std::cout << "Meow\n";
    }
};

int main()
{
    //inheritance -> class can receive methods abd attri from another class -> reuse similar code

    Dog dog;
    dog.eat();

    Cat cat;
    cat.eat();
    cat.meow();

    return 0;
}