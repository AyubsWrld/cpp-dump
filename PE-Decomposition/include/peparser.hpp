#pragma once
#include <fstream>
#include <optional>
#include <iostream>
#include "WINNT.hpp"

namespace Flexxer
{
  class NTParser 
  {
    std::ifstream m_executable;

    public:

      NTParser(const char* executable_path);
      NTParser(const NTParser& other) = delete; 
      NTParser& operator==(const NTParser& other) = delete; 

      ~NTParser();

      bool IsValid() ;

      bool ImageType();

      std::optional<IMAGE_DOS_HEADER> ParseHeader();

    private:

      bool IsOpen() const { return m_executable.is_open(); }

      LONG HeaderOffset();

  };
}
