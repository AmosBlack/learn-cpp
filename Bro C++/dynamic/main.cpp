#include<iostream>

int main()
{
    int *pnum = NULL;

    pnum = new int;
    *pnum = 14;

    std::cout << pnum << "\n" << *pnum << std::endl;

    delete pnum; //important to release the memory back
    return 0;
}