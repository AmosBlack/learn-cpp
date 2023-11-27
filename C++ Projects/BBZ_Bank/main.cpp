#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>

//functions
void welcome();

void openAccount(std::fstream& file);
void accessAccount(std::fstream& file, std::string &name, std::string &pin, double &balance);
bool verifyAccount(std::string &pin);
//void findName()
void bankingActions(std::string &name, std::string &pin, double &balance, std::fstream& file, bool &run);

bool deposit(double &balance,std::fstream& file, std::string &name);
bool withdraw(double &balance, std::string &pin,std::fstream& file, std::string &name);
void checkBalance(double &balance);
void updateBalance(double &balance, std::fstream& file, std::string &name);

void closeFile(std::fstream& file);

// enum Booleans { true=0, false=-1};

int main()
{
    //data vars
    double balance = 0;
    std::string pin;
    std::string name;

    //db
    std::fstream db;
    db.open("data.csv", std::ios :: in | std::ios :: app);
    if(!db.is_open()){
        std::cout << "FILE DID NOT OPEN!";
        main();
    }
    //runtime
    bool running = true;

    //options-(i)
    welcome();

    char userInput;
    std::cin >> userInput;
    userInput = tolower(userInput);

    //user input controls
    switch(userInput){
        case 'a':
            accessAccount(db, name, pin, balance);
            std::cout << "Welcome " << name << "!\n";
            break;
        case 'o':
            openAccount(db);
            break;
        case 'l':
            closeFile(db);
            std::cout << "Have a nice day!" << std::endl;
            running = false;
            break;
        default:
            std::cout << "INVALID INPUT!\n";
    }

    while(running){

        bankingActions(name, pin, balance, db, running);

        //clear cin buffer
        std::cin.clear();
        while (std::cin.get() != '\n'){}
    }

    return 0;
}

//WELCOME MESSAGE
void welcome(){
    std::cout << "********* BBZ BANK **********\n";
    std::cout << "[a]ccess account\n" << "[o]pen acount\n" << "[l]eave\n";
    std::cout << "Your choice: ";
}

//OPEN ACCOUNT
void openAccount(std::fstream& file){
    std::string name, pin, temp, line;
    double balance = 0;
    std::cout << "* ACCOUNT FORMATION PROCESS *\n";
    int i;
    bool nameFound = false;

    do{
        nameFound = false;
        std::cout << "Enter name: ";
        std::cin >> name;
        //FI* THIS SIHT
        file.clear(); // Clear any error flags
        file.seekg(0, std::ios::beg); // Move file cursor to the beginning of the file
        i = 0;
        while(getline(file, line)){
            if(i % 3 == 0 && name == line){
                nameFound = true;
                break;
            }
            else{
                i += 1;
            }
        }
        if (nameFound) {
            std::cout << "Name already exists. Please enter a different name." << std::endl;
        }
    }while(nameFound);
    
    do{
        std::cout << "Enter 4 char pin: ";
        std::cin >> pin;
        std::cout << "Confirm 4 char pin: ";
        std::cin >> temp;

        if(pin!=temp){
            std::cout << "Pin doesn't match\n";
        }
        else if(pin.length() != 4){
            std::cout << "Pin should be 4 chars only\n";
        }
    }while(pin != temp || pin.length() != 4);

    do{
        std::cout << "Enter initial deposit(>$50): ";
        std::cin >> balance;
        if(balance < 50){
            std::cout << "Minimum deposit is $50\n";
        }
    }while(balance < 50);
    
    //append data
    file.clear();
    file << name << "\n" << pin << "\n" << balance << "\n";
    closeFile(file);
    std::cout << "ACCOUNT CREATED\n";

    main();
}

//ACCESS ACCOUNT
void accessAccount(std::fstream& file, std::string &name, std::string &pin, double &balance){
    std::cout << "*** ACCOUNT LOGIN PROCESS ***\n";
    std::string temp_name, line;
    bool nameFound = false;

    do{
        std::cout << "Enter name: ";
        std::cin >> temp_name;
        int i = 0;
        file.clear(); // Clear any error flags
        file.seekg(0, std::ios::beg); // Move file cursor to the beginning of the file
        while(getline(file, line)){
            if(i % 3 == 0 && temp_name == line){
                nameFound = true;
                name = temp_name;
                file >> pin;
                file >> balance;
                break;
            }
            else{
                i += 1;
            }
        }
    }while(!nameFound);
}

//VERIFY PIN
bool verifyAccount(std::string &pin){
    std::string attempt;
    std::cout << "Enter pin: ";
    std::cin >> attempt;
    if(attempt != pin) {
        std::cout << "WRONG PIN\n";
        return false;
    }
    return true;
}

//DEPOSIT MONEY
bool deposit(double &balance,std::fstream& file, std::string &name){
    double deposit;
    do{
        std::cout << "Enter deposit amount: ";
        std::cin >> deposit;
        if(deposit <= 0){
            std::cout << "Deposit amount must be greater than zero\n";
        }
    }while(deposit <= 0);
    balance += deposit;
    updateBalance(balance, file, name);
    std::cout << "Your new balance is " << balance << std::endl;
    return true;
}

//WITHDRAW MONEY
bool withdraw(double &balance, std::string &pin,std::fstream& file, std::string &name){
    double withdraw;
    do{
        std::cout << "Enter withdrawal amount: ";
        std::cin >> withdraw;
        if(withdraw <= 0){
             std::cout << "Withdrawal amount must be greater than zero\n";
        }
    }while(withdraw <= 0);

    if(verifyAccount(pin) && balance >= withdraw){
        balance -= withdraw;
        updateBalance(balance, file, name);
        std::cout << "Your new balance is " << balance << "\n";
        return true;
    }
    else{
        if(withdraw > balance){
            std::cout << "Insufficient funds\n";
            return false;
        }
        std::cout << "Enter correct pin\n";
        return false;
    }
}

//CHECK BALANCE
void checkBalance(double &balance){
    std::cout << "Your balance is " << balance << std::endl;
}

//UPDATE BALANCE
void updateBalance(double &balance, std::fstream& file, std::string &name){
    file.clear(); // Clear any error flags
    file.seekg(0, std::ios::beg); // Move file cursor to the beginning of the file
    
    std::string line;
    std::vector<std::string> db;

    while(getline(file, line)){
        db.push_back(line);
    }

    std::fstream filedb;
    filedb.open("data.csv", std::ios::out);


    for(int i = 0; i < db.size(); i++){
        if(i % 3 == 0 && name == db.at(i)){
                db.at(i+2) = std::to_string(balance);
        }
        
        filedb << db.at(i) << "\n";
    }

}

//CLOSE FILE
void closeFile(std::fstream& file){
    file.close();
}

void bankingActions(std::string &name, std::string &pin, double &balance, std::fstream& file, bool &run){
    char userInput;

    std::cout << "********* BBZ BANK **********\n";
    std::cout << "[c]heck balance\n" << "[d]eposit money\n" << "[w]ithdraw money\n" << "[e]xit\n";
    std::cout << "*****************************\n";

    std::cout << "Your choice: ";
    std::cin >> userInput;
    userInput = tolower(userInput);

    switch(userInput){
        case 'c':
            checkBalance(balance);
            break;
        case 'd':
            deposit(balance, file, name);
            break;
        case 'w':
            withdraw(balance, pin, file, name);
            break;
        case 'e':
            std::cout << "*****************************\n";
            std::cout << "Have a nice day!\n";
            std::cout << "*****************************\n";
            run = false;
            return;
        default :
            std::cout << "INVALID INPUT!";
    }

}

