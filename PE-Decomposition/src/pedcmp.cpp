#include "peparser.hpp"

int main (int argc, char *argv[]) 
{
  Flexxer::NTParser Parser("/mnt/e/C++/PE-Decomposition/src/B3.exe") ;

  auto PEHeader{Parser.ParseHeader()};

  if(PEHeader.has_value())
  {
    std::cout << std::hex << PEHeader.value().e_magic << std::endl;
  }
  return 0;
}
