#ifndef ANDMULT_HPP
#define ANDMULT_HPP

#include <iostream>
#include <fuzzy/and.hpp>
#include <core/expression.hpp>

namespace fuzzy {
    template <class T>
    class AndMult : public And<T>{
    public:
        T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T AndMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        // TODO : L ANDMULT R =  L * R
        return (lvalue * rvalue);
    }
}

#endif // ! ANDMULT_HPP
