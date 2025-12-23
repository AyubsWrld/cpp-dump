#include <print>
#include <utility>
#include <memory>

template<typename> 
struct TDelegate;

template<typename InReturnType, typename... Params>
struct TDelegate<InReturnType(Params...)>
{
    using   ReturnType      =   InReturnType; 
    using   FunctionType    =   InReturnType(Params...); 
};

#define DECLARE_DELEGATE(DELEGATE_NAME, RETURN_TYPE, ...) \
    using DELEGATE_NAME = TDelegate<RETURN_TYPE(__VA_ARGS__)>;

struct Object 
{
    template<typename T>
    Object(T&& object)
        : m_object(std::make_unique<Model<T>>(std::forward<T>(object)))
    {}
    struct Concept
    {
        virtual     ~Concept()  =   default;
        virtual void Tell()     =   0;
    };

    template<typename T>
    struct Model : public Concept 
    {
        Model(const T& object)
            : m_type_erased_obj(object)
        {}

        virtual void Tell() override { m_type_erased_obj.Tell() ; }

        T m_type_erased_obj;
    };

    void Tell(){ m_object->Tell(); }

private:

    std::unique_ptr<Concept> m_object;

};

struct A 
{
    virtual void See() { std::println("A"); }
};

struct B : public A
{
    void Tell() { std::println("Foo"); }
};

A* GetA() { return new B{}; }

B* GetB()
{
    B b{};
    return std::move(&b);
}

template<typename T>
void f(T&& x){ std::println("{}", x); }

template<typename To, typename From> 
constexpr To* Cast(From* V)
{
    static_assert(std::is_convertible_v<From, To> && "Faied assertion");
    return static_cast<To*>(V);
}



int main (int argc, char *argv[]) 
{
    Object b = *(dynamic_cast<B*>(GetA()));
    b.Tell();
    return 0;
}
