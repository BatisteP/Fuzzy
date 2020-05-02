#ifndef ISTRAPEZOIDALRIGHT_HPP
#define ISTRAPEZOIDALRIGHT_HPP

#include <iostream>
#include <exceptions/trapezoidalexception.hpp>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTrapezoidalRight : public Is<T> {
    public:
        IsTrapezoidalRight(T, T);
        virtual ~IsTrapezoidalRight();
        virtual std::ostream &PrintOn(std::ostream &) const;
        virtual T evaluate(core::Expression<T>*) const;
        virtual void setMidRight(T);
        virtual void setMax(T);

    private:
        T midRight;
        T max;
    };

    template <class T>
    IsTrapezoidalRight<T>::IsTrapezoidalRight(T _midRight, T _max)
        : midRight(_midRight), max(_max) {}

    template <class T>
    IsTrapezoidalRight<T>::~IsTrapezoidalRight() {}

    template <class T>
    void IsTrapezoidalRight<T>::setMidRight(T _midRight) {
        midRight = _midRight;
    }

    template <class T>
    void IsTrapezoidalRight<T>::setMax(T _max) {
        max = _max;
    }

    template <class T>
    T IsTrapezoidalRight<T>::evaluate(core::Expression<T> * o) const {
        // TODO : if operand is a null pointer launch exception
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        // TODO : Where c = midRight < d = max are not met, launch exception
        if (!(midRight < max)) {
            throw exceptions::TrapezoidalException<T>("Conditions are not met, i.e : midRight < max");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        // TODO : if (x > d)
        if (xValue > max) {
            return 0;
        }

        // TODO : if (x < c)
        if (xValue < midRight) {
            return 1;
        }

        // TODO : if (x >= c) and (x <= d)
        return ((xValue >= midRight && xValue <= max) ? ((max - xValue) / (max - midRight)) : 0);
    }

    template<class T>
    std::ostream &IsTrapezoidalRight<T>::PrintOn(std::ostream &os) const {
        T xmin = 0.0;
        T xmax = 10.0;
        os << 'x' << ','<<'y'<<std::endl;
        for (T i = xmin; i < xmax; i = i + 0.1){
            core::ValueModel<T> a = core::ValueModel<T>(i);
            os << i <<','<< evaluate(&a);
            os << std::endl;
        }
        return os;
    }
}

#endif // ! ISTRAPEZOIDALRIGHT_HPP
