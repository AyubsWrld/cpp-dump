#include <iostream>
#include <cstdlib>
#include <new>


int main (int argc, char *argv[]) 
{

  std::string* obj = (std::string*) malloc(8);

  {
    std::string* str = new (obj) std::string{'#', '#', '#', '#', '#', '#', '#', '#' };

    str->~basic_string();

  }

  std::cout << *obj << std::endl;

  std::string* str = new (obj) std::string{'$', '$', '$', '$', '$', '$', '$', '$' };

  std::cout << *obj << std::endl;

  return 0;
}

