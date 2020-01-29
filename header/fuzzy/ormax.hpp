//
// Created by bp71 on 29/01/2020.
//

#ifndef SUGENO_ORMAX_HPP
#define SUGENO_ORMAX_HPP
#include <fuzzy/or.hpp>

namespace fuzzy {
    template <class T>
    class OrMax : public Or<T>{
    public:
        T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T OrMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {

        T lvalue = l -> evaluate();
        T rvalue = r -> evaluate();
        return (lvalue >= rvalue ? lvalue : rvalue);
    }
}
#endif //SUGENO_ORMAX_HPP
