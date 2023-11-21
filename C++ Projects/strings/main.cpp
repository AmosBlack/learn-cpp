#include <iostream>

int main(){
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin,name); //to allow storing spaces as well

    name.empty() ? std::cout << "You didn't enter your name" : std::cout << "Verified Username\n"; //isEmpty

    name.length() > 12 ? std::cout << "Your name can't be over 12 characters" : std::cout << "Welcome " << name << std::endl; //lengthOfString
    
    std::cout << name.at(0) << "\n"; //access specific inde* of string

    std::cout << name.insert(0,"@") << "\n"; //insert content at specific inde*

    std::cout << name.append("@gmail.com") << "\n"; //append content to string

    //last name
    std::cout << name.erase(0, name.find(' ')) << std::endl; //remove specific portion of string

    return 0;
}