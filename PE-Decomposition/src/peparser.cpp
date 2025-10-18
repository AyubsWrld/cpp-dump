#include "peparser.hpp"

Flexxer::NTParser::NTParser(const char* executable_path)
  : m_executable(executable_path, std::ios_base::binary)
{
  if(!m_executable.is_open()){ /* Do something here */ }
}

Flexxer::NTParser::~NTParser()
{
  if(!m_executable.is_open()) m_executable.close();
}

bool Flexxer::NTParser::IsValid() 
{
  if(IsOpen())
  {
    USHORT PE_HEADER_CONTAINER{}; 
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&PE_HEADER_CONTAINER), sizeof(USHORT));
    m_executable.seekg(0);
    std::cout << m_executable.tellg() << std::endl;
    return PE_HEADER_CONTAINER == PE_FLAG;
  }
  std::cout << "File is not open" << std::endl;
  return false;
}

bool Flexxer::NTParser::ImageType() 
{
  if(IsOpen())
  {
    USHORT PE_HEADER_CONTAINER{}; 
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&PE_HEADER_CONTAINER), sizeof(USHORT));
    m_executable.seekg(0);
    std::cout << std::hex << PE_HEADER_CONTAINER << std::endl; 
    return PE_HEADER_CONTAINER == PE_FLAG;
  }
  std::cout << "File is not open" << std::endl;
  return false;
}

LONG Flexxer::NTParser::HeaderOffset()
{
  if(IsOpen())
    return -1;

  return -1;
}

std::optional<IMAGE_DOS_HEADER> Flexxer::NTParser::ParseHeader()
{
  if(IsOpen() && IsValid())
  {
    IMAGE_DOS_HEADER NTHeader{};
    m_executable.read(reinterpret_cast<std::ifstream::char_type*>(&NTHeader), sizeof(IMAGE_DOS_HEADER));
    return std::optional<IMAGE_DOS_HEADER>{NTHeader};
  }
  return {};
}

