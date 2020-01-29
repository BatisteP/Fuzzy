//
// Created by bp71 on 29/01/2020.
//

#ifndef SUGENO_ANDMULT_HPP
#define SUGENO_ANDMULT_HPP


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

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();
        return (lvalue * rvalue );
    }
}
#endif //SUGENO_ANDMULT_HPP
