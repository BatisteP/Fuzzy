#ifndef SUGENOTHEN_HPP
#define SUGENOTHEN_HPP

#include <iostream>
#include <fuzzy/then.hpp>

namespace fuzzy {
    template <class T>
    class SugenoThen : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
        virtual T getPremiseValue() const;
        virtual void setPremiseValue(T);

    public:
       mutable   T premiseValue;
    };

    template <class T>
    T SugenoThen<T>::evaluate(core::Expression<T> * l, core::Expression<T> * r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        premiseValue = l->evaluate() ;
        T rvalue = r->evaluate();

        // TODO : L SUGENOTHEN R = L * R
        return premiseValue * rvalue;
    }

    template <class T>
    T SugenoThen<T>::getPremiseValue() const {
        return premiseValue;
    }

    template <class T>
    void SugenoThen<T>::setPremiseValue(T p) {
        premiseValue = p;
    }
}

#endif // ! SUGENOTHEN_HPP
