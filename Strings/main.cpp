#include <format>
#include <iostream>

int main (int argc, char *argv[]) 
{
    int x{};
    int* p = &x;
    std::cout << p << std::endl;
    return 0;
}
