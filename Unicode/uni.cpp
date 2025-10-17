#include<iostream>
#include<string.h>
#include<fstream>



int main (int argc, char *argv[]) 
{
  std::ifstream File("/mnt/e/Games/Ghost of Tsushima DC/cache_pc/psarc/gapack_misc_a_Unpacked/adachi.xpps", std::ios_base::binary );

  char buffer[64];
  File.read(buffer, 64);

  std::cout << buffer << std::endl;
  File.close();
  return 0;
}
