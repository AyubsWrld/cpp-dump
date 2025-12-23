#include <filesystem>
#include <stdlib.h>
#include <cassert>
#include <string>
#include <print>
#include <iostream>


void RunFromPath(const std::string& command, std::filesystem::directory_iterator path )
{
    assert(!path->is_directory() && "Entry must be a directory");
    auto temp = std::filesystem::current_path();
    system(command.c_str());
}

int main (int argc, char *argv[]) 
{
    auto s = std::filesystem::directory_iterator();
    const auto& current_path = std::filesystem::current_path();
    for( const auto& s : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        if ( s.is_directory() )
        {
            std::filesystem::current_path(s); 
            system("git remote -v");
            std::cout << s.path() << "\n";
        }
    }

    std::filesystem::current_path(current_path);
    return 0;
}
