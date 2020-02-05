#ifndef AGGMAX_HPP
#define AGGMAX_HPP

#include <iostream>
#include <fuzzy/agg.hpp>

namespace fuzzy {
    template <class T>
    class AggMax : public Agg<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T AggMax<T>::evaluate(core::Expression<T> * l, core::Expression<T> * r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l -> evaluate();
        T rvalue = r -> evaluate();

        // TODO : L AGGMAX R = MAX(L, R)
        return (lvalue >= rvalue ? lvalue : rvalue);
    }
}

#endif // ! AGGMAX_HPP
