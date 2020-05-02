#ifndef IS_HPP
#define IS_HPP

#include <iostream>
#include <core/unaryexpression.hpp>

namespace fuzzy {
    template <class T>
    class Is : public core::UnaryExpression<T> {
        virtual std::ostream &PrintOn(std::ostream &) const=0;
    };
}

#endif // ! IS_HPP
