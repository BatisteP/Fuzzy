#ifndef SUGENOTHEN_HPP
#define SUGENOTHEN_HPP

#include <iostream>
#include <fuzzy/then.hpp>

namespace fuzzy {
    template <class T>
    class SugenoThen : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
        virtual T premiseValue() const;
        virtual void setPremiseValue(T);

    private:
        T premiseValue;
    };

    template <class T>
    T SugenoThen<T>::evaluate(core::Expression<T> * l, core::Expression<T> * r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        // TODO : L SUGENOTHEN R = ?
        return null;
    }

    template <class T>
    T SugenoThen<T>::premiseValue() const {
        return premiseValue;
    }

    template <class T>
    void SugenoThen<T>::setPremiseValue(T p) {
        premiseValue = p;
    }
}

#endif // ! SUGENOTHEN_HPP
