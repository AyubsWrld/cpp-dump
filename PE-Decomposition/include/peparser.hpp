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

      bool IsPortableExecutable();

      bool ImageType();

      std::optional<IMAGE_DOS_HEADER> ParseMSDOSHeader();
      std::optional<IMAGE_FILE_HEADER> ParsePEHeader(LONG HeaderOffset);

    private:

      void Rewind() { m_executable.seekg(0); }  // Not terribly descriptive 
      bool IsOpen() const { return m_executable.is_open(); }

      LONG HeaderOffset();

  };
}
