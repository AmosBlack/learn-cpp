#include<iostream>

class Account{
    public:
        std::string name;
    private:
        std::string pin;
        double balance;
    
    //GETTERS
    //redundant
    std::string getPin(){
        return pin;
    }
    
    double getBalance(){
        return balance;
    }

    //SETTERS
    void setPin(std::string &pin){
        this->pin = pin;
    }

    void setBalance(double &balance){
        this->balance = balance;
    }

    //CONSTRUCTOR
    Account(std::string &name, std::string &pin, double &balance){
        this->name = name;
        this->pin = pin;
        this->balance = balance;
    }

    //VERIFY    
    bool verify(){
        std::string attempt;
        std::cout << "Enter pin: ";
        std::cin >> attempt;

        if(attempt == pin){
            //add error flags
            return true;
        }
        return false;
    }

    //DEPOSIT
    bool deposit(double &amount){
        system("clear");
        double amount;
        std::cout << "Enter the deposit amount: ";

        if(amount > 0){
            //output error flags
            balance += amount;
            return true;
        }
        return false;
    }

    //WITHDRAW
    bool withdraw(double &amount){
        system("clear");
        double amount;
        std::cout << "Enter the withdrawal amount: ";

        if(balance >= amount && amount > 0){
            balance -= amount;
            //output error flags
            return true;
        }
        return false;
    }





};

int main(){


    return 0;
}