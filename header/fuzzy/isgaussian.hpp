#ifndef ISGAUSSIAN_HPP
#define ISGAUSSIAN_HPP

#include <iostream>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsGaussian : public Is<T> {
    public:
        IsGaussian();
        virtual ~IsGaussian();
    };

    template <class T>
    IsGaussian<T>::IsGaussian() {}

    template <class T>
    IsGaussian<T>::~IsGaussian() {}
}

#endif // ! ISGAUSSIAN_HPP
