#ifndef ISTRAPEZOIDAL_HPP
#define ISTRAPEZOIDAL_HPP

#include <iostream>
#include <exceptions/trapezoidalexception.hpp>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTrapezoidal : public Is<T> {
    public:
        IsTrapezoidal(T, T, T, T);
        virtual ~IsTrapezoidal();

        virtual T evaluate(core::Expression<T>*) const;
        virtual void setMin(T);
        virtual void setMidLeft(T);
        virtual void setMidRight(T);
        virtual void setMax(T);

    private:
        T min;
        T midleft;
        T midright;
        T max;
    };

    template <class T>
    IsTrapezoidal<T>::IsTrapezoidal(T _min, T _midleft, T _midright, T _max)
        : min(_min), midleft(_midleft), midright(_midright), max(_max) {}

    template <class T>
    IsTrapezoidal<T>::~IsTrapezoidal() {}

    template <class T>
    void IsTrapezoidal<T>::setMin(T _min) {
        min = _min;
    }

    template <class T>
    void IsTrapezoidal<T>::setMidLeft(T _midleft) {
        midleft = _midleft;
    }

    template <class T>
    void IsTrapezoidal<T>::setMidRight(T _midright) {
        midright = _midright;
    }

    template <class T>
    void IsTrapezoidal<T>::setMax(T _max) {
        max = _max;
    }

    template <class T>
    T IsTrapezoidal<T>::evaluate(core::Expression<T> * o) const {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        // TODO : Where a = min < b = midleft < c = midright < d = max
        if (!(min < midleft && midleft < midright && midright < max)) {
            throw exceptions::TrapezoidalException<T>("Conditions are not met, i.e : min < midleft < midright < max");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        if (xValue < min || xValue > max) {
            // TODO : if (x < a) or (x > d)
            return 0;
        }

        if (xValue >= midleft && xValue <= midright) {
            // TODO : if (x >= b) && (x <= c)
            return 1;
        }

        if (xValue >= mid && xValue <= midleft) {
            // TODO : if (x >= a) && (x <= b)
            return ((xValue - mid) / (midleft - mid));
        }

        if (xValue >= midright && xValue <= max) {
            // TODO : if (x >= c) && (x <= d)
            return ((max - xValue) / (max - midright));
        }

        return 0;
    }
}

#endif // ! ISTRAPEZOIDAL_HPP
