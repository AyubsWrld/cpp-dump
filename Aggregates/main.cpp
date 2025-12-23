#include <print>
#include <memory>


struct Object 
{
    template<typename T> 
    Object(T&& m_obj)
        : object(std::make_unique<Model<T>>(std::forward<T>(m_obj)))
    {}

    void Speak() { object->Speak(); }

    struct Concept 
    {
        virtual ~Concept() = default; 
        virtual void Speak() = 0;
    };


    template<typename T>
    struct Model : public Concept 
    {
        T obj; 
        Model(const T& t) 
            : obj(t)
        {}
        void Speak() override 
        {
            obj.Speak();
        }
    };

    std::unique_ptr<Concept> object ;
};

struct Foo 
{
    void Speak() { std::println("Foo"); }
};

int main(int argc, char *argv[])
{
    Object s = Foo{}; 

    s.Speak();
    return EXIT_SUCCESS;
}
