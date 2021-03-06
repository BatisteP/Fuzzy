#ifndef ANDMIN_HPP
#define ANDMIN_HPP

#include <iostream>
#include <fuzzy/and.hpp>

namespace fuzzy {
    template <class T>
    class AndMin : public And<T> {
    public:
        T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T AndMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        // TODO : L ANDMIN R =  MIN(L, R)
        return (lvalue < rvalue ? lvalue : rvalue);
    }
}

#endif // ! ANDMIN_HPP
