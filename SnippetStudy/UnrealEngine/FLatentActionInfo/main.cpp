#include <iostream>
#include <print>

#define FORCENOINLINE [[__gnu__::__noinline__]] 

class UObject; 
class FObjectActions
{
    struct FActionList
    {
        std::size_t Num(std::int32_t UUID){ return 0; }
    };

    FActionList Actionlist; 
};

FObjectActions* GetActionsForObject(UObject* InActionObject);

/*
template<typename ActionType, typename PredicateType>
ActionType* FindExistingActionWithPredicate(UObject* InActionObject, std::int32_t UUID, const PredicateType& FilterPredicate)
{
FObjectActions* ObjectActionList = GetActionsForObject(InActionObject);
if ((ObjectActionList != nullptr) && (ObjectActionList->ActionList.Num(UUID) > 0))
{
    for (auto It = ObjectActionList->ActionList.CreateKeyIterator(UUID); It; ++It)
    {
    ActionType* Item = (ActionType*)(It.Value());
    if (FilterPredicate(Item))
    {
        return Item;
    }
    }
}

return nullptr;
}
*/

template <typename ActionType>
ActionType* FindExistingAction(UObject* InActionObject, std::int32_t UUID)
{
    struct FFirstItemPredicate
    {
        FORCENOINLINE bool operator()(void*) const { return true; }
    };

}

struct Foo
{
    FORCENOINLINE bool operator()(void*) const { std::print("Hello world\n"); return true; }
};

int main (int argc, char *argv[]) 
{
    Foo{}(NULL);
    return 0;
}
