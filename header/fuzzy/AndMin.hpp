//
// Created by bp71 on 28/01/2020.
//

#ifndef SUGENO_ANDMAX_HPP
#define SUGENO_ANDMAX_HPP
#include <iostream>
#include <core/binaryexpression.hpp>
namespace fuzzy{
    template <class T>
    class AndMax : public And<T>{
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;

    };
    T AndMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
        if (_left == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (_right == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }
        T lvalue = l -> evaluate();
        T rvalue = r -> evaluate();
        return (lvalue < rvalue ? lvalue : rvalue);
    }
}



#endif //SUGENO_AND_HPP
#endif //SUGENO_ANDMAX_HPP
