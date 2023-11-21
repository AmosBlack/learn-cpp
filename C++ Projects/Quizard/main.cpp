#include <iostream>

int main() {

    std::string questions[] = {
            "1.What year was C++ created?: ",
            "2.Who invented C++: ",
            "3. What is the predecessor of C++: ",
            "4. Is the Earth flat ?"
    };
    std::string options[][2] = {
            {"A. 1969", "B. 1985"},
            {"A. Guido van Rossum", "B. Bjarne Stroustrup"},
            {"A. C#", "B. C"},
            {"A. Yes", "B. No"}
    };

    char answers[] = {'B', 'B', 'B', 'B'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score = 0;

    for(int i = 0; i < size; i++){
        std::cout << "****************************\n";
        std::cout << questions[i] << "\n";
        std::cout << "****************************\n";

        for(int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
             std::cout << options[i][j] << "\n";
        }

        std::cin >> guess;
        guess = toupper(guess);

        if(guess == answers[i]){
            std::cout << "CORRECT\n";
            score++;
        }
        else{
            std::cout << "WRONG\n";
            std::cout << "Answer: " << answers[i] << "\n";
        }
    }

    std::cout << "****************************\n";
    std::cout << "*          RESULTS           *\n";
    std::cout << "****************************\n";
    std::cout << "# of Questions: " << size << "\n";
    std::cout << "SCORE:" << (score/(double)size)*100 << "%";
    //typecasting init
    return 0;
}
