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
        T midLeft;
        T midRight;
        T max;
    };

    template <class T>
    IsTrapezoidal<T>::IsTrapezoidal(T _min, T _midLeft, T _midRight, T _max)
        : min(_min), midLeft(_midLeft), midRight(_midRight), max(_max) {}

    template <class T>
    IsTrapezoidal<T>::~IsTrapezoidal() {}

    template <class T>
    void IsTrapezoidal<T>::setMin(T _min) {
        min = _min;
    }

    template <class T>
    void IsTrapezoidal<T>::setMidLeft(T _midLeft) {
        midLeft = _midLeft;
    }

    template <class T>
    void IsTrapezoidal<T>::setMidRight(T _midRight) {
        midRight = _midRight;
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

        // TODO : Where a = min < b = midLeft < c = midRight < d = max are not met, launch exception
        if (!(min < midLeft && midLeft < midRight && midRight < max)) {
            throw exceptions::TrapezoidalException<T>("Conditions are not met, i.e : min < midLeft < midRight < max");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        // TODO : if (x < a) or (x > d)
        if (xValue < min || xValue > max) {
            return 0;
        }

        // TODO : if (x >= b) and (x <= c)
        if (xValue >= midLeft && xValue <= midRight) {
            return 1;
        }

        // TODO : if (x >= a) and (x <= b)
        if (xValue >= min && xValue <= midLeft) {
            return ((xValue - min) / (midLeft - min));
        }

        // TODO : if (x >= c) and (x <= d)
        return ((xValue >= midRight && xValue <= max) ? ((max - xValue) / (max - midRight)) : 0);
    }
}

#endif // ! ISTRAPEZOIDAL_HPP
