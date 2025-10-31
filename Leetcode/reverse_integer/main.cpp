#include <iostream>
#include <stdint.h>
#include <limits>
#include <bitset>

namespace Flexxer 
{
  template <typename T>
  constexpr uint8_t getWidth(T x){
    return sizeof(T) * 8;
  }
}

template <typename T>
class Solution
{
  int reverse(T x)
  {
    if constexpr (!std::is_same<T, int>::value)
      return 0; 
    std::cout << Flexxer::getWidth(x) << std::endl;
    return 0; 
  }
};


template<typename T>

int main (int argc, char *argv[]) 
{
  constexpr int x{10};
  std::cout << Flexxer::getWidth(x) << std::endl;
  std::cout << std::bitset<Flexxer::getWidth(x)>(x) << std::endl;
  return 0;
}
