#ifndef ISTRIANGLE_HPP
#define ISTRIANGLE_HPP

#include <core/expression.hpp>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTriangle : public Is<T> {
    public:
        IsTriangle(T , T , T );
        virtual ~IsTriangle();

        virtual T evaluate(core::Expression<T>*) const;

    private:
        T min;
        T mid;
        T max;
    };

    template<class T>
    IsTriangle<T>::IsTriangle(T _min, T _mid, T _max)
            : min(_min), mid(_mid), max(_max) {}

    template <class T>
    IsTriangle<T>::~IsTriangle() {}

    template <class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        T oValue = o->evaluate();
        if (oValue >= max || oValue <= min){
            return 0;
        }

        return ( oValue < mid ? (oValue - min)/(mid - min) : (max - oValue)/(max - mid));
    }
}

#endif // ! ISTRIANGLE_HPP
