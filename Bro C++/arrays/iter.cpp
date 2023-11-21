#include<iostream>
int main()
{
    std::string students[] = {"Naruto", "Sasuke", "Sakura", "Kakashi"};
    
    //normal for loop with conditions works as well
    //foreach is more convenient, less fle*ible

    for(std::string student : students){
        std::cout << student << "\n";
    }

    return 0;
}