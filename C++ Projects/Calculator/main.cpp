#include <iostream>
using namespace std;

void calc(int, int, int);

int main(){
    char op;
    
    int a,b;

    cout << "****** Calculator *******\n";
    cout << "Enter an operator (+/-*): ";
    cin >> op; 

    cout << "Enter #1: ";
    cin >> a;

    cout << "Enter #2: ";
    cin >> b;

    calc(a,b,op);
    cout << "*************************" << endl;
    return 0;
}


void calc(int num1, int num2, int op){
    int res;
    switch(op){
        case '+':
            res =  num1+num2;
            cout << "Result: " << res << "\n";
            return;             
        case '-':
            res = num1-num2;
            cout << "Result: " << res << "\n"; 
            return;
        case '*':
            res =  num1 * num2;
            cout << "Result: " << res << "\n";
            return;
        case '/':
            res =  num1/num2;
            cout << "Result: " << res << "\n";
            return;
        default:
            cout << "Please choose an operator from +,-,/,*";
            return;
    }
}