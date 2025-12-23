#include <iostream>
#include <type_traits>
#include <functional>

template <typename DelegateSignature>
class TDelegate
{

};

template <typename InRetValType, typename... ParamTypes>
class TDelegate<InRetValType(ParamTypes...)> 
{

public:

    using RetValType = InRetValType;
    using TFuncType  = InRetValType(ParamTypes...);

    TDelegate() = default;
    TDelegate(TDelegate&& Other) = default;
    TDelegate& operator=(TDelegate&& Other) = default;
    ~TDelegate() = default;

};

class UObjectManager 
{
    std::function<void()> S { [](){ std::cout << "Hello World"; } };
};



int main () 
{

    std::cout << std::is_same<void(void),void(void)>::value;
    std::cout << std::is_same<void(void), TDelegate<void(void)>::TFuncType>::value;
    return 0;
}
