#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    std::cout << "**********************\n" << "Welcome to Tic Tac Toe\n" << "**********************\n";
    drawBoard(spaces);

    while(running){
        playerMove(spaces, player);
        //drawBoard(spaces);
        if(checkWinner(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!" << std::endl;
    std::cout << "**********************\n";
    return 0;
}

void drawBoard(char *spaces){
    //grid
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
    std::cout << "     |     |     " << "\n";
}
void playerMove(char *spaces, char player){
    int number;
    do{
        std::cout << "Enter location (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){

    for(int i = 0; i < 3; i++){
        if(spaces[i*3] == spaces[3*i + 1] && spaces[3*i+1] == spaces[3*i+2] && spaces[3*i] != ' '){\
            drawBoard(spaces);
            spaces[i*3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            return true;
        }
    }
    for(int i = 0; i < 3; i++){
        if(spaces[i] == spaces[i+3] && spaces[i+3] == spaces[i + 6] && spaces[i] != ' '){
            drawBoard(spaces);
            spaces[i] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            return true;
        }
    }
    //diagonal
    if(spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' '){
        drawBoard(spaces);
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if(spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' '){
        drawBoard(spaces);
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }
    return true;
}
bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "TIED!\n";
    return true;
}