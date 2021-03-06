#ifndef THENMIN_HPP
#define THENMIN_HPP

#include <iostream>
#include <fuzzy/then.hpp>

namespace fuzzy {
    template <class T>
    class ThenMin : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T ThenMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        // TODO : L THENMIN R =  MIN(L, R)
        return (lvalue < rvalue ? lvalue : rvalue);
    }
}

#endif // ! THENMIN_HPP
