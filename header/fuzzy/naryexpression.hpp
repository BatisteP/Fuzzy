#ifndef NARYEXPRESSION_HPP
#define NARYEXPRESSION_HPP

#include <iostream>
#include <vector>
#include <core/expression.hpp>

namespace fuzzy {
    template <class T>
    class NaryExpression {
    public:
        NaryExpression();
        virtual ~NaryExpression();

        virtual T evaluate(std::vector<core::Expression<T>*>) const = 0;
    };

    template <class T>
    NaryExpression<T>::NaryExpression() {}

    template <class T>
    NaryExpression<T>::~NaryExpression() {}
}

#endif // ! NARYEXPRESSION_HPP
