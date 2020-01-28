#ifndef UNARYEXPRESSION_HPP
#define UNARYEXPRESSION_HPP

#include <iostream>
#include <core/expression.hpp>
#include <exceptions/nullpointerexception.hpp>

namespace core {
    template <class T>
    class UnaryExpression {
    public:
        UnaryExpression();
        virtual ~UnaryExpression();

        virtual T evaluate(Expression<T>* ) const = 0;
    };

    template <class T>
    UnaryExpression<T>::UnaryExpression() {}

    template <class T>
    UnaryExpression<T>::~UnaryExpression() {}
}

#endif // ! UNARYEXPRESSION_HPP
