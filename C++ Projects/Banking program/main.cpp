#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    do{
        std::cout << "********* BBZ BANK **********\n" << "Enter your choice\n" << "1. Show Balance\n" << "2. Deposit Money\n" << "3. Withdraw Money\n" << "4. Leave\n";
        std::cin >> choice;

        std::cin.clear();
        while (std::cin.get() != '\n')
        {
            continue;
        }
        /*std::cin.clear();
        fflush(stdin);
        UNDEFINED BEHAVIOUR
        */

        switch(choice)
        {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4:
                std::cout << "Thanks for visiting!" << std::endl;
                break;
            default: std::cout << "Invalid Choice!\n";
        }
    }while(choice != 4);

    return 0;

}

void showBalance(double balance){
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << "\n";
}

double deposit(){
    double amount;
    std::cout << "Enter amount to be deposited: ";
    if(amount > 0){
        std::cin >> amount;
        return amount;
    }
    else{
        std::cout << "Too little money to be deposited\n";
        return 0;
    }
}

double withdraw(double balance){
    double amount;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;

    //balance check
    if(amount <= balance && amount > 0) {
        return amount;
    }
    else{
        std::cout << "Amount entered is too large\n";
        return 0;
    }
}