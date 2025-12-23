#include <iostream> 
#include <print> 
#include <type_traits> 
#include <queue> 
#include <optional> 
#include <utility>
#include <functional>
#include <vector>
#include <string>

/* Goal: Write the minigame system. 
 * Should either accept a timer or an action based.
 *
 */
struct AGameModeBase{};
using FName = std::string; 

enum class EWinCondition : uint8_t
{
    WC_UNDEFINED,
    WC_TimeBased,
    WC_EliminationBased,
    WC_PuzzleBased,
    WC_MAX
};

enum class EMinigameDifficulty
{
    MGD_UNDEFINED,
    MGD_Easy,
    MGD_Medium,
    MGD_Hard,
    MGD_Insane,
};

struct FMinigame
{
    using   TDelegate    =   const std::function<void()>& ;

    FName				        LevelIdentifier;
    EWinCondition		    WinCondition;
    EMinigameDifficulty Difficulty;
    
    FMinigame()		=	delete;
    ~FMinigame()	=	default;
    FMinigame(FName LevelIdentifier, EWinCondition WinCondition, EMinigameDifficulty Difficulty);
    
    FMinigame(const FMinigame& InMinigame) = delete;
    FMinigame(const FMinigame&& InMinigame) = delete;
    
    FMinigame& operator=(const FMinigame& InMinigame) noexcept	=	delete;
    FMinigame& operator=(FMinigame&& InMinigame) noexcept		=	delete;
   
    /* Let this run and then call the delegate */ 
    void BeginMinigame(TDelegate Delegate);
    void BeginMinigame();
    void EndMinigame();
};

constexpr EWinCondition operator|(EWinCondition lhs, EWinCondition rhs)
{
    using TUnderlying = std::underlying_type<EWinCondition>::type;
    return static_cast<EWinCondition>(static_cast<TUnderlying>(lhs) | static_cast<TUnderlying>(rhs));
}


class FMinigameManager
{
    std::queue<FMinigame> Minigames{};

public: FMinigameManager(std::initializer_list<FMinigame>&& Minigames);

    const std::queue<FMinigame>& GetMinigames() const
    {
        return Minigames;
    }

    std::optional<std::reference_wrapper<FMinigame>> NextMinigame()
    {
        if(!Minigames.empty())
        {
            Minigames.pop();
            return {Minigames.front()} ;
        }
        return std::nullopt;
    }
};


// FMinigameManager::FMinigameManager(std::initializer_list<FMinigame>&& minigames)
//     : Minigames(minigames)
// {
//
// }

struct Base
{
    virtual void DoSomething(int x);
};

struct Derived : public Base
{
    using Super = Base; 
    virtual void DoSomething(int x) override ;
};

void Base::DoSomething(int x)
{
    std::print("Base: {}\n", x);
}

void Derived::DoSomething(int x)
{
    Super::DoSomething(x);
    std::print("Derived: {}\n", x + 1);
}


int main (int argc, char *argv[]) {
    EWinCondition WinCondition = EWinCondition::WC_TimeBased | EWinCondition::WC_EliminationBased;

    Derived{}.DoSomething(30);
    return 0;
}
