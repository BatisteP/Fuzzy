#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <iostream>

namespace core {
    template <class T>
    class Expression {
    public:
        Expression();
        virtual ~Expression();

        virtual T evaluate() const = 0;
    };

    template <class T>
    Expression<T>::Expression() {}

    template <class T>
    Expression<T>::~Expression() {}
}

#endif // ! EXPRESSION_HPP