#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
void print(T collection, int size){
    for(int i = 0; i < size; i++){
        cout << collection[i] << endl;
    }
}

template <typename T>
void print(T collection){
    print(collection, collection.size());
}


int main(){
    cout << "What did you eat: ";
    string item;
    cin >> item;

    ofstream file('foods');
    file << item;
    file.close();
    system("pause");
    return 0;
}