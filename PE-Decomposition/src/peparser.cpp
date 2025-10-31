#include "peparser.hpp"

Flexxer::NTParser::NTParser(const char* executable_path)
  : m_executable(executable_path, std::ios_base::binary)
{
  if(!m_executable.is_open()){ /* Do something here */ }
}

Flexxer::NTParser::~NTParser()
{
  if(IsOpen()) m_executable.close();
}

bool Flexxer::NTParser::IsPortableExecutable() 
{
  if(IsOpen())
  {
    USHORT PE_HEADER_CONTAINER{}; 
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&PE_HEADER_CONTAINER), sizeof(USHORT));
    std::cout << std::hex << PE_FLAG << std::endl;
    std::cout << std::hex << PE_HEADER_CONTAINER << std::endl;
    Rewind();
    return PE_HEADER_CONTAINER == PE_FLAG;
  }
  return false;
}

bool Flexxer::NTParser::ImageType() 
{
  if(IsOpen())
  {
    USHORT PE_HEADER_CONTAINER{}; 
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&PE_HEADER_CONTAINER), sizeof(USHORT));
    Rewind();
    return PE_HEADER_CONTAINER == PE_FLAG;
  }
  return false;
}

LONG Flexxer::NTParser::HeaderOffset()
{
  if(IsOpen())
    return -1;

  return -1;
}

std::optional<IMAGE_DOS_HEADER> Flexxer::NTParser::ParseMSDOSHeader()
{
  if(IsOpen())
  {
    IMAGE_DOS_HEADER NTHeader{};
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&NTHeader), sizeof(IMAGE_DOS_HEADER));
    return std::optional<IMAGE_DOS_HEADER>{NTHeader};
  }
  return {};
}

std::optional<IMAGE_FILE_HEADER> Flexxer::NTParser::ParsePEHeader(LONG HeaderOffset)
{
  if(IsOpen())
  {
    IMAGE_FILE_HEADER Header;
    m_executable.seekg(HeaderOffset);
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&Header), sizeof(IMAGE_FILE_HEADER)) ;
    Rewind();
    return std::optional<IMAGE_FILE_HEADER>{Header};
  }
  return {};
}


