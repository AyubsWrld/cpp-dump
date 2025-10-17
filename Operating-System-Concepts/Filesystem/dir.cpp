#include <iostream>


struct FINode
{
  long long   Hash;
  const char* Blocks[8];
};

static FINode* FInodeTable[30] = {};  // Zero initializes

struct FDirectory 
{
  FDirectory* Parent; 
  FDirectory* Children[3]; 
  const char* Path; 
};

int main (int argc, char *argv[]) 
{
  return 0;
}
