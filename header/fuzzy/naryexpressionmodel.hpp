//
// Created by bp71 on 18/02/2020.
//

#ifndef SUGENO_NARYEXPRESSIONMODEL_HPP
#define SUGENO_NARYEXPRESSIONMODEL_HPP

#include <iostream>
#include <core/expression.hpp>
#include <exceptions/nullpointerexception.hpp>
#include <vector>

namespace fuzzy {
    template <class T>
    class NaryExpressionModel {
    public:
        NaryExpressionModel();
        virtual ~NaryExpressionModel();
        T evaluate() const;
        T evaluate(std::vector<core::Expression<T>*>) const;
    };

    template <class T>
    NaryExpression<T>::NaryExpression() {}

    template <class T>
    NaryExpression<T>::~NaryExpression() {}

    template<class T>
    T NaryExpression<T>::evaluate(std::vector<core::Expression<T> *>) const {
        return nullptr;
    }
}

#endif //SUGENO_NARYEXPRESSIONMODEL_HPP
