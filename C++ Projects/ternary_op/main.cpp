#include <iostream>
using namespace std;

int main(){
   int a,b,c;
   a = 7;
   b = 3;
   c = 9;
   (a > b && a > c) ? cout << a : ((b > c) ? cout << b : cout << c);

   int grade;
   cin >> grade;
   grade >= 60 ? cout << "You Passed!" : cout << "You Failed";

   int num;
   cin >> num;
   num % 2 ? cout << "EVEN" : cout << "ODD";

   bool hungry = true;
   cout << (hungry ? "True" : "False") << endl;

   return 0;
}