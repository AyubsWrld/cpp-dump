#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <print>
#include <type_traits> 
#include <string>

void s()
{
    std::print("s() called\n");
}
enum class ENetMode 
{
    NM_UNDEF,
    NM_Client, 
    NM_Standalone,
    NM_DedicatedServer,
    NM_MAX,
};

enum class EWinCondition
{
    WC_UNDEF,
    WC_TimeBased,
    WC_EliminationBased,
    WC_DelegateBased,
    WC_MAX,
};

struct FGameModeBase
{
    using Players = char; 

    EWinCondition   WinCondition{};
    Players         PlayerList[30]{};
    FGameModeBase()
        : 
            WinCondition(EWinCondition::WC_UNDEF)
    {

    } 
};

class UObject
{
    // virtual ~UObject(){}; 
}; 

class UWorld  : public UObject
{
    ENetMode NetMode{}; 

public:
    UWorld()
        : NetMode(ENetMode::NM_UNDEF)
    {}

    ENetMode GetNetMode()  const
    {
        return NetMode;
    }
};

class UWorldSubsytem 
{
    virtual void OnWorldBeginPlay(UWorld& InWorld) const = 0;
    virtual bool ShouldSpawnSubsystem(UObject* InWorld) const = 0;
};


struct FMinigame 
{

    template<typename ReturnType, typename... Args>
    void Play(ReturnType(v)(Args...)) const  { 
        std::print("Playing\n");
        v();
    };
};


enum class EMinigameTag
{
    MT_UNDEF,
    MT_HideAndSeek,
    MT_CrossTheBridge,
    MT_Telephone,
    MT_MAX,
};

struct UMinigameManager
{
    std::vector<FMinigame> Minigames;

    void Play()
    {
        for ( const auto& game : Minigames)
        {
            game.Play(s);
        }
    }
};

struct FNested 
{
    int m_list[10]{};

    auto&& operator[](this auto&& self, int index)
    {
        return self.m_list[index];
    }
};

template<typename F, typename... Args>
using FPointer = F(Args...);

void foo(void(*callable)())
{
    if (callable)
    {
        callable();
    }
}

template<typename DelegateType> 
class TDelegate{};

template<typename InRetVal, typename... Args> 
class TDelegate<InRetVal(Args...)>
{
public:
    using   TReturnType   =     InRetVal;
    using   TFunctionType =     InRetVal(Args...);

    TFunctionType* f;

    TDelegate(TFunctionType s) 
        : f(s)
    {

    }

    TReturnType operator()(Args... args) 
    {
        return (*f)(args...);
    }
};


int OnEnd() // Some callable
{
    return 10;
}


int main (int argc, char *argv[]) 
{
    std::print("{}\n",std::is_same<TDelegate<int(void)>::TFunctionType, void(void)>::value);
    std::print("{}\n",std::is_same<TDelegate<int(int,int)>::TFunctionType, int(int)>::value);

    UMinigameManager v;
    v.Minigames.emplace_back(FMinigame{});
    v.Minigames.emplace_back(FMinigame{});

    v.Play();
    return EXIT_SUCCESS;
}
