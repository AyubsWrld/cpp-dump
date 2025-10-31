#include "peparser.hpp"

int main (int argc, char *argv[]) 
{
  Flexxer::NTParser Parser("/mnt/e/C++/PE-Decomposition/src/B3.exe") ;

  auto DOSHeader{Parser.ParseMSDOSHeader().value()};
  auto PEHeader{Parser.ParsePEHeader(DOSHeader.e_lfanew + sizeof(LONG))};

  if(PEHeader.has_value())
  {
    std::cout << std::hex << PEHeader->Machine << std::endl;
  }

  return 0;
}
