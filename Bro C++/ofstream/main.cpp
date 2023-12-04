#include <iostream>
#include <fstream>
using namespace std;

// template <typename T>
// void print(T collection, int size){
//     for(int i = 0; i < size; i++){
//         cout << collection[i] << endl;
//     }
// }

// template <typename T>
// void print(T collection){
//     print(collection, collection.size());
// }


int main(){
    fstream file;
    
    //WRITE
    file.open("file.txt", ios::out);    //out=write;
    if(!file.is_open()){
        cout << "ERROR" << endl;
    }
    else{
        file << "Hello\nHang in there\n";
        cout << "SUCCESS-WRITE" << endl;
        file.close();
    }
    //APPEND
    file.open("file.txt", ios::app);    //app=append;
    if(!file.is_open()){
        cout << "ERROR" << endl;
    }
    else{
        file << "Paramedics are going to reach you soon!";
        cout << "SUCCESS-APPEND" << endl;
        file.close();
    }
    //READ
    file.open("file.txt", ios::in);    //in=read;
    if(!file.is_open()){
        cout << "ERROR" << endl;
    }
    else{
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    }


    return 0;
}