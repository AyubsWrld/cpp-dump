#include <iostream>

int main (int argc, char *argv[]) {
  int nzero{4} ;
  int zero{} ;

  std::cout << (nzero & nzero) << std::endl;
  std::cout << (zero & zero) << std::endl;
  return 0;
}
