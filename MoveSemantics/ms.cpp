#include <iostream> 
#include <cassert> 

template<typename T>
struct A
{
    T* m_ptr; 
    std::size_t m_size; 

    A(std::size_t size = 0)
    {
        m_ptr = new T[size]{3};
        m_size = size; 
    }

    T& operator[](std::size_t index)
    {
        assert((index < m_size) && "Invalid" );
        return m_ptr[index];
    }
};

int main (int argc, char *argv[]) 
{
    A<int> V  = A<int>{10};

    for (std::size_t i{} ; i < V.m_size ; i++)
    {
        std::cout << V[i] << std::endl; 
    }
    return 0;
}
