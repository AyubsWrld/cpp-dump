#pragma once 
#include <iostream>


struct Bar 
{
    void operator()()
    {
        std::cout << "Hello world\n" ; 
    }
};

struct Foo
{
    static Bar B; 
};
