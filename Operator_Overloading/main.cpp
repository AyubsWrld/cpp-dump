#include <iostream> 
#include <print> 
#include <span> 
#include <vector>
#include <cstddef>
#include <type_traits>

struct A 
{
    int x{};
};

struct B 
{
    int x{};
    explicit operator A()
    {
        return A{x}; 
    }
};

struct C
{
    const int x, y; 
};

// C& C::operator=(const C& copy)
// {
//     x = copy.x;
//     y = copy.y;
//     return *this;
// }

int main (int argc, char *argv[]) 
{
    std::print("{}", std::is_copy_assignable_v<C>); 
    return 0;
}
