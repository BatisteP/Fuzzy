//
// Created by Yassine Sameh on 02/05/2020.
//

#ifndef SUGENO_EQUAL_HPP
#define SUGENO_EQUAL_HPP

#include <fuzzy/or.hpp>

namespace fuzzy {
    template <class T>
    class Equal : public Or<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T Equal<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        T lvalue = l->evaluate();
        T rvalue = r->evaluate();

        return (lvalue == rvalue) ? lvalue : nullptr;
    }
}


#endif //SUGENO_EQUAL_HPP
