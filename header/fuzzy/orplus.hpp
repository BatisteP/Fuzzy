#ifndef ORPLUS_HPP
#define ORPLUS_HPP

#include <iostream>
#include <fuzzy/or.hpp>

namespace fuzzy {
    template <class T>
    class OrPlus : public Or<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T OrPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        // TODO : L ORPLUS R =  L + R - (R * L)
        return (lvalue + rvalue - (lvalue * rvalue));
    }
}

#endif // ! ORPLUS_HPP
