#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);


int main() {
    char player, computer;
    while(true){
        player = getUserChoice();
        std::cout << "You chose: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer chose: ";
        showChoice(computer);

        chooseWinner(player, computer);
        std::cout << std::endl;
    }


    return 0;
}

char getUserChoice(){

    char player;
    std::cout << "***** Welcome to RPS *****\n";
    std::cout << "***** Moves *****\nrock(r)\npaper(p)\nscissors(s)\n";
    do{
        std::cout << "Please enter your choice: ";
        std::cin >> player;
    }while( player != 'r' && player!= 'p' && player != 's');

    return player;
}
char getComputerChoice(){
    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num) {
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
        default:
            return 's';
    }
}

void showChoice(char choice){
    switch (choice) {
        case 'r':
            std::cout << "Rock\n";
            break;
        case 'p':
            std::cout << "Paper\n";
            break;
        case 's':
            std::cout << "Scissors\n";
            break;
    }
}

void chooseWinner(char player, char computer){

    if(player == computer){
        std::cout << "***** It's a Tie *****";
        return;
    }

    switch (player) {
        case 'r':
            if( computer == 's'){
                std::cout << "***** The Player Wins *****";
            }
            else{
                std::cout << "***** The Computer Wins *****";
            }
            break;
        case 's':
            if( computer == 'p'){
                std::cout << "***** The Player Wins *****";
            }
            else{
                std::cout << "***** The Computer Wins *****";
            }
            break;
        case 'p':
            if( computer == 'r'){
                std::cout << "***** The Player Wins *****";
            }
            else{
                std::cout << "***** The Computer Wins *****";
            }
            break;
        default:
            std::cout << "***** Invalid Result *****";
    }
}