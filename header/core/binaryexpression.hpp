#ifndef BINARYEXPRESSION_HPP
#define BINARYEXPRESSION_HPP

#include <iostream>
#include <core/expression.hpp>
#include <exceptions/nullpointerexception.hpp>

namespace core {
    template <class T>
    class BinaryExpression {
    public:
        BinaryExpression();
        virtual ~BinaryExpression();

        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };


    template <class T>
    BinaryExpression<T>::BinaryExpression() {}

    template <class T>
    BinaryExpression<T>::~BinaryExpression() {}
}

#endif // ! BINARYEXPRESSION_HPP