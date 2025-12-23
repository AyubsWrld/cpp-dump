#include <iostream>
#include <type_traits>

struct FDefaultDelegateUserPolicy{}; 

template<typename DelegateSignature, typename UserPolicy = FDefaultDelegateUserPolicy>
struct TDelegate{};


template<typename InReturnValType, typename... ParamTypes>
struct TDelegate<InReturnValType(ParamTypes...)>
{
  using RetValType                = InReturnValType;
  using FuncType                  = InReturnValType(ParamTypes...);
};


template<auto V1, decltype(V1) V2, typename T>
struct values_equal : std::bool_constant<V1 == V2>
{
    using type = T;
};

// Deduce type of non-template type parameters
template<auto S>
void foo(decltype(S) v)
{
    std::cout << v << std::endl; 
}

int main()
{
    return EXIT_SUCCESS;
}
