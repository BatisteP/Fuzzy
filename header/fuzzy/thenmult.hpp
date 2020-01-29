#ifndef THENMULT_HPP
#define THENMULT_HPP

#include <iostream>
#include <fuzzy/then.hpp>

namespace fuzzy {
    template <class T>
    class ThenMult : public Then<T> {
    public:
        T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T ThenMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        // TODO : THEN MULT
       return null;
    }
}

#endif // ! THENMULT_HPP
