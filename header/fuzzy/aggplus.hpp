#ifndef AGGPLUS_HPP
#define AGGPLUS_HPP

#include <iostream>
#include <fuzzy/agg.hpp>

namespace fuzzy {
    template <class T>
    class AggPlus : public Agg<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T AggPlus<T>::evaluate(core::Expression<T> * l, core::Expression<T> * r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l -> evaluate();
        T rvalue = r -> evaluate();

        // TODO : L AGGPLUS R = L + R - (L * R)
        return (lvalue + rvalue - (lvalue * rvalue));
    }
}

#endif // ! AGGPLUS_HPP
