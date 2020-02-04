#ifndef ISTRIANGLE_HPP
#define ISTRIANGLE_HPP

#include <core/expression.hpp>
#include <exceptions/triangleexception.hpp>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTriangle : public Is<T> {
    public:
        IsTriangle(T , T , T );
        virtual ~IsTriangle();

        virtual T evaluate(core::Expression<T>*) const;
        virtual void setMin(T);
        virtual void setMid(T);
        virtual void setMax(T);

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
    void IsTriangle<T>::setMin(T _min) {
        min = _min;
    }

    template <class T>
    void IsTriangle<T>::setMid(T _mid) {
        mid = _mid;
    }

    template <class T>
    void IsTriangle<T>::setMax(T _max) {
        max = _max;
    }

    template <class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        // TODO : Where a = min < m = mid < b = max
        if (!(min < mid && mid < max)) {
            throw exceptions::TriangleException<T>("Conditions are not met, i.e : min < mid < max");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        if (xValue <= min || xValue >= max) {
            // TODO : if (x <= a) or (x >= b)
            return 0;
        }

        if (xValue > min && xValue <= mid) {
            // TODO : if (x > a) and (x <= m)
            return ((xValue - min) / (mid - min));
        }

        if (xValue > mid && xValue < max) {
            // TODO : if (x > m) and (x < b)
            return ((max - xValue) / (max - mid));
        }

        //return (xValue < mid ? (xValue - min)/(mid - min) : (max - xValue)/(max - mid));
        return 0;
    }
}

#endif // ! ISTRIANGLE_HPP
