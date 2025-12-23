#pragma once 
#include <memory> 
#include "TMinigameConcrete.hpp"

namespace LO
{
    struct Object
    {
        template<typename T>
        Object(T&& obj)
            : m_ptr(std::make_unique<Model<T>>(std::forward<T>(obj)))
        {}

        struct Concept
        {
            virtual void Speak() const = 0; 
            virtual ~Concept() = default;
        };

        template<typename T>
        struct Model : public Concept
        {
            Model(const T& obj)
                : m_obj(std::move(obj))
            {}

            virtual void Speak() const override 
            {
                m_obj.Speak();
            }

            T m_obj;
        };

        std::unique_ptr<Concept> m_ptr; 

        void Speak() const { m_ptr->Speak(); }

    };
}

