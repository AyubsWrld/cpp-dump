#include <concepts>
#include <iostream>
#include <climits>
#include <format>
#include <print>
#include <ranges>
#include <vector>
#include <string_view>
#include <cstdint>
#include <sstream>
#include <bitset>
#include <fstream>
#include <cstdio>
#include <algorithm>


// struct A {};
// static_assert(!std::is_union_v<A>);
//
// typedef union
// {
//     int a;
//     float b;
// } B;
// static_assert(std::is_union_v<B>);
//
// struct C { B d; };
// static_assert(!std::is_union_v<C>);
//
// static_assert(!std::is_union_v<int>);


using namespace std::literals;

template<typename... T> 
struct typelist{}; 


template<typename U, typename... T>
constexpr bool is_of_type()
{
    return ((std::is_same_v<U,T>) || ...);
}

template<typename U, typename... T>
struct type_in  
{
    constexpr static bool value = is_of_type<U, T...>(); 
};

template<typename T>
concept A = requires(T a){ type_in<T, int, char, void>::value ; };

inline std::string __itohex(std::size_t i)
{
    return ((std::stringstream{} << std::hex << i).str()) ; 
}


template<typename T>
concept Callable = requires(T a){ std::is_invocable<T, void>::value; };

template<typename T>
requires Callable<T>
struct Defer 
{
    T a;
    ~Defer(){ a(); }
};


std::string __println(std::string s)
{
    s = ( s.size() % 2 != 0 ?   "0" + s : s) ; 
    std::size_t unpadded_size{s.size()};
    std::stringstream ss; 
    ss << std::uppercase; 
    for(int x{}; auto i : s)
    {
        if(x % 2 == 0 && x != 0)
        {
            ss << " ";
        }
        ss << i ;
        x++;
    }
    auto a  = [&]{
        std::stringstream ts; 
        for(std::size_t i{}; i  <= (8 - (unpadded_size / 2 ))  ;  i++ )
        {
            ts << "00 " ; 
        }
        ts << ss.str(); 
        return ts; 
    };
    return a().str(); 
}

template <typename T>
T read_from_little_endian(const unsigned char * buff)
{
    T val {}; // Initializes a member

    for(std::size_t i = 0; i < sizeof(T); ++i) // loops over everything 
        val |= buff[i] << (i*CHAR_BIT);

    return val;
}

std::string __printlvl(const std::size_t& lvl)
{
    return ( __println(__itohex(lvl)) + " | " ) ;
}

/* Unlinkely */ 
[[nodiscard]] std::string __println(const std::array<char,16>& v)
{
    std::stringstream ss{};
    ss << std::hex << std::uppercase; 
    std::span sv{v}; 
    for(int i : sv.subspan<0,7>()) 
        if( i < 16) [[unlikely]]
        {
            ss <<   "0" + __itohex(i) ; 
            // ss << ( i < 16 ? (  "0" + __itohex(i) ) : ( __itohex(i) )) << " " ;
        }
        else
        {
            ss << __itohex(i) ; 
        }
    ss << " " ;
    for(int i : std::span{v}.subspan<8>())
        ss << ( i < 16 ? (  "0" + __itohex(i) ) : ( __itohex(i) )) << " " ;
    return ss.str();
}

void __readlines(std::ifstream& fresource)
{
    std::array<char,16> buffer{};
    std::size_t lcout{}; 
    while(fresource.read(buffer.data(), sizeof(buffer)) && lcout < 256)
    {
        std::cout << __printlvl(lcout) << __println(buffer)  << std::endl;
        lcout += 16; 
    }
}

template <typename T>
T read_from_big_endian(unsigned char* buff)
{
    T val {};

    for(std::size_t i = 0; i < sizeof(T); ++i)
        val |= buff[sizeof(T)-1-i] << (i*CHAR_BIT);

    return val;
}

template<typename T, std::size_t N>
T f(T(&&arr)[N])
{
    for(auto i: arr)
    {
        std::cout << i << std::endl;
    }
    return {};
}

std::ostream& operator<<(std::ostream& o, std::byte b)
{
    std::cout << std::bitset<8>(std::to_integer<int>(b));
    return o;
}


int main ()
{

    // std::ifstream fstream ;
    // fstream.open("main.cpp", std::ios_base::binary);
    //
    // __readlines(fstream);


    
    unsigned char V0{std::numeric_limits<unsigned char>::max() - 1}; 
    unsigned char V1{std::numeric_limits<unsigned char>::max()}; 
    unsigned char V2{std::numeric_limits<unsigned char>::min() + 10}; 

    // std::cout << std::bitset<8>(V0) << std::endl;
    // std::cout << std::bitset<8>(V1) << std::endl;
    // std::cout << std::bitset<8>(( V1 << 4)) << std::endl;
    // std::cout << std::bitset<8>(( V1 << (sizeof(decltype(V1))*8 ) )) << std::endl;
    // std::cout << std::bitset<8>(( V2 << (sizeof(decltype(V1))*8 ) )) << std::endl;
    // std::cout << std::bitset<8>(( V2 >> (sizeof(decltype(V1))*8 ) )) << std::endl;

    std::cout << any_of_same<int,char,char> ;
    return 0;
}


