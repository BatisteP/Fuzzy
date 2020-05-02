#ifndef ISTRAPEZOIDALLEFT_HPP
#define ISTRAPEZOIDALLEFT_HPP

#include <iostream>
#include <exceptions/trapezoidalexception.hpp>
#include <fuzzy/is.hpp>

namespace fuzzy {
    template <class T>
    class IsTrapezoidalLeft : public Is<T> {
    public:
        IsTrapezoidalLeft(T, T);
        virtual ~IsTrapezoidalLeft();
        virtual std::ostream &PrintOn(std::ostream &) const;
        virtual T evaluate(core::Expression<T>*) const;
        virtual void setMidLeft(T);
        virtual void setMin(T);

    private:
        T min;
        T midLeft;

    };

    template <class T>
    IsTrapezoidalLeft<T>::IsTrapezoidalLeft(T _min, T _midLeft)
        : min(_min), midLeft(_midLeft) {}

    template <class T>
    IsTrapezoidalLeft<T>::~IsTrapezoidalLeft() {}

    template <class T>
    void IsTrapezoidalLeft<T>::setMidLeft(T _midLeft) {
        midLeft = _midLeft;
    }

    template <class T>
    void IsTrapezoidalLeft<T>::setMin(T _min) {
        min = _min;
    }

    template <class T>
    T IsTrapezoidalLeft<T>::evaluate(core::Expression<T> * o) const {
        // TODO : if operand is a null pointer launch exception
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        // TODO : Where a = min < b = midLeft are not met, launch exception
        if (!(min < midLeft)) {
            throw exceptions::TrapezoidalException<T>("Conditions are not met, i.e : min < midLeft");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        // TODO : if (x < a)
        if (xValue < min) {
            return 0;
        }

        // TODO : if (x > b)
        if (xValue > midLeft) {
            return 1;
        }

        // TODO : if (x >= a) and (x <= b)
        return ((xValue >= min && xValue <= midLeft) ? ((xValue - min) / (midLeft - min)) : 0);
    }

    template<class T>
    std::ostream &IsTrapezoidalLeft<T>::PrintOn(std::ostream &os ) const {
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

#endif // ! ISTRAPEZOIDALLEFT_HPP
