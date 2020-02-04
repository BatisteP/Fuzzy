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
        // TODO : if operand is a null pointer launch exception
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        // TODO : Where a = min < m = mid < b = max are not met, launch exception
        if (!(min < mid && mid < max)) {
            throw exceptions::TriangleException<T>("Conditions are not met, i.e : min < mid < max");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        // TODO : if (x <= a) or (x >= b)
        if (xValue <= min || xValue >= max) {
            return 0;
        }

        // TODO : if (x > a) and (x <= m)
        if (xValue > min && xValue <= mid) {
            return ((xValue - min) / (mid - min));
        }

        // TODO : if (x > m) and (x < b)
        return ((xValue > mid && xValue < max) ? ((max - xValue) / (max - mid)) : 0);
    }
}

#endif // ! ISTRIANGLE_HPP
