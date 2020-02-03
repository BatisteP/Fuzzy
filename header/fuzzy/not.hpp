#ifndef NOT_HPP
#define NOT_HPP

#include <iostream>
#include <core/unaryexpression.hpp>

namespace fuzzy {
    template <class T>
    class Not : public core::UnaryExpression<T> {

    };
}

#endif // ! NOT_HPP
