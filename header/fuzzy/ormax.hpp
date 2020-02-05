#ifndef ORMAX_HPP
#define ORMAX_HPP

#include <iostream>
#include <fuzzy/or.hpp>

namespace fuzzy {
    template <class T>
    class OrMax : public Or<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T OrMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l -> evaluate();
        T rvalue = r -> evaluate();

        // TODO : L ORMAX R =  MAX(L, R)
        return (lvalue >= rvalue ? lvalue : rvalue);
    }
}

#endif // ! ORMAX_HPP
