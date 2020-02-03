#ifndef ISTRAPEZOIDAL_HPP
#define ISTRAPEZOIDAL_HPP

#include <iostream>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTrapezoidal : public Is<T> {
    public:
        IsTrapezoidal();
        virtual ~IsTrapezoidal();
    };

    template <class T>
    IsTrapezoidal<T>::IsTrapezoidal() {}

    template <class T>
    IsTrapezoidal<T>::~IsTrapezoidal() {}
}

#endif // ! ISTRAPEZOIDAL_HPP
