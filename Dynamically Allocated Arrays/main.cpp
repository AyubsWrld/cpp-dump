#include <iostream>
#include <cstddef>

int main (int argc, char *argv[]) 
{
  std::size_t size{}; 
  std::cout << "Please enter how many names you would like to enter: " << std::endl; 
  std::cin >> size; 

  auto p{ new std::string[size]{} } ;

  decltype(p)  begin{p}; 
  decltype(p)  end{p + size}; 
  
  for(; begin != end ; ++begin) 
  {
    std::cin >> *begin; 
  }

  begin = p;

  for(; begin != end ; ++begin) 
  {
    std::cout << *begin << std::endl;;
  }

  return 0;
}
