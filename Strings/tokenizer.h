#include <iostream> 
#include <algorithm> 
#include <string> 


namespace Flexxer
{
	[[maybe_unused]] std::vector<std::string> tokenize_line(const std::string& line)
	{
	  std::string::const_iterator begin { line.cbegin() };
	  std::string::const_iterator end   { line.end()    };
	  const std::string::difference_type count { std::count(begin, end, ' ') + 1 } ; 

	  std::vector<std::string> Tokenized; Tokenized.reserve(count);

	  std::string::size_type slow{}; 
	  std::string::size_type fast{}; 
	  for( std::string::value_type i : line )
	  {
	    if( i == ' ' && slow != fast)
	    {
	      Tokenized.emplace_back(line.substr(slow, fast - slow));
	      fast++;
	      slow = fast;
	    }
	    else
	      fast++;
	  }
	  Tokenized.emplace_back(line.substr(slow, fast - slow));
	  return Tokenized; 
	}
}

