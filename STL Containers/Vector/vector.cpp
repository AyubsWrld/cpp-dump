#include <vector>
#include <type_traits>
#include <iostream>


int main (int argc, char *argv[]) 
{
  const std::vector<int>& rV = { 1, 2, 3};
  std::remove_reference<decltype(rV)>::type V(4);
  std::is_same<std::remove_reference<decltype(V)>, const std::vector<int>>::value ;
  return 0;
}
