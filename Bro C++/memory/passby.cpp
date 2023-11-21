#include<iostream>

void swap(std::string a, std::string b);

int main()
{
    std::string y = "Kool-Aid";
    std::string w = "Water";

    //passby value = creates copy 
    //pasby ref = sends address (best practice)

    std::cout << "Y: " << &y << "\n" << "W: " << &w << "\n";

    swap(y,w);

    // std::cout << "Y: " << y << "\n" << "W: " << w << "\n";

    return 0;
}

void swap(std::string a, std::string b){ //forpassbyref, use address of operator

    std::cout << "Y: " << &a << "\n" << "W: " << &b << "\n";

    std::string temp;
    temp  = a;
    a = b;
    b = temp;
}
// PASS BY REF ADDRESSES IN MAIN VS SWAP
// Y: 0x7fffffffd450
// W: 0x7fffffffd470
// Y: 0x7fffffffd450
// W: 0x7fffffffd470
// PASS BY VAL ADDRESSES IN MAIN VS SWAP
// Y: 0x7fffffffd410
// W: 0x7fffffffd430
// Y: 0x7fffffffd450
// W: 0x7fffffffd470