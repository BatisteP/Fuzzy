#ifndef NARYEXPRESSION_HPP
#define NARYEXPRESSION_HPP

#include <iostream>
#include <vector>
#include <core/expression.hpp>

namespace core {
    template <class T>
class NaryExpression {
    public:

        NaryExpression(){};
        virtual ~NaryExpression(){};

        virtual T evaluate(std::vector<const core::Expression<T>*>*) const = 0;
    };


}

#endif // ! NARYEXPRESSION_HPP
