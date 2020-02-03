#ifndef ISTRAPEZOIDALLEFT_HPP
#define ISTRAPEZOIDALLEFT_HPP

#include <iostream>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTrapezoidalLeft : public Is<T> {
    public:
        IsTrapezoidalLeft();
        virtual ~IsTrapezoidalLeft();
    };

    template <class T>
    IsTrapezoidalLeft<T>::IsTrapezoidalLeft() {}

    template <class T>
    IsTrapezoidalLeft<T>::~IsTrapezoidalLeft() {}
}

#endif // ! ISTRAPEZOIDALLEFT_HPP
