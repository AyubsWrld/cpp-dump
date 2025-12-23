#include <print> 
#include <memory>
#include <array>

template<typename T>
struct AutoPointer 
{

    AutoPointer(const AutoPointer& other) = delete; 
    AutoPointer(T** object)
        : m_ptr(*object)
    {
        std::println("Object Created");
    }

    AutoPointer(T* object)
        : m_ptr(object)
    {
        std::println("Object Created");
    }


    ~AutoPointer()
    {
        std::println("Object Destroyed");
        delete m_ptr;
    }

    T operator*()
    {
        return *m_ptr;
    }

    T* operator++()
    {
        return m_ptr++;
    }
private:
    T* m_ptr;
};

AutoPointer V = new int{3}; 

int main (int argc, char *argv[]) 
{
    AutoPointer V = new int{3}; 
    auto S = *V; 
    std::print("{}\n", std::is_same_v<decltype(S), int>);
    std::print("{}\n", *V);
    return EXIT_SUCCESS;
}
