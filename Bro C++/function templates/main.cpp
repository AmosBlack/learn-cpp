#include<iostream>

// function blueprint with different types
template <typename T, typename U>
auto max(T x, U y){
    return (x > y) ? x : y;
} 

int main()
{
    std::cout << max(1,2.1) << std::endl;
    return 0;
}