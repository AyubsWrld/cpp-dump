#include <iostream>

int main (int argc, char *argv[]) 
{
    int x = 3;  

    // lX gets a copy of x within it's definition. 
    auto lX = [x](){ std::cout << x ; } ;  

    lX(); 

    return 0;
}
