#ifndef ISTRAPEZOIDALRIGHT_HPP
#define ISTRAPEZOIDALRIGHT_HPP

#include <iostream>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTrapezoidalRight : public Is<T> {
    public:
        IsTrapezoidalRight();
        virtual ~IsTrapezoidalRight();
    };

    template <class T>
    IsTrapezoidalRight<T>::IsTrapezoidalRight() {}

    template <class T>
    IsTrapezoidalRight<T>::~IsTrapezoidalRight() {}
}

#endif // ! ISTRAPEZOIDALRIGHT_HPP
