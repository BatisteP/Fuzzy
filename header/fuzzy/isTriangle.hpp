//
// Created by bp71 on 29/01/2020.
//

#ifndef SUGENO_ISTRIANGLE_HPP
#define SUGENO_ISTRIANGLE_HPP
#include <core/expression.hpp>
#include <fuzzy/is.hpp>
namespace fuzzy {
    template <class T>
    class IsTriangle : public Is<T>{
    public:
        T evaluate(core::Expression<T>*) const;
        IsTriangle(T , T , T );

    private:
        T min;
        T mid;
        T max;
    };

    template <class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const {

        T oValue = o->evaluate();
        if (oValue >= max || oValue <= min){
            return 0;
        }

        return ( oValue < mid ? (oValue - min)/(mid - min) : (max - oValue)/(max - mid));
    }

    template<class T>
    IsTriangle<T>::IsTriangle(T _min, T _mid, T _max) :
    min(_min), mid(_mid), max(_max)
    {

    }
}
#endif //SUGENO_ISTRIANGLE_HPP
