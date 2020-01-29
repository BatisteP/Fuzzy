//
// Created by bp71 on 29/01/2020.
//

#ifndef SUGENO_ORPLUS_HPP
#define SUGENO_ORPLUS_HPP
#include <fuzzy/or.hpp>

namespace fuzzy {
    template <class T>
    class OrPlus : public Or<T>{
    public:
        T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };

    template <class T>
    T OrPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {

        T lvalue = l -> evaluate();
        T rvalue = r -> evaluate();
        //pas sur
        return (lvalue + rvalue );
    }
}
#endif //SUGENO_ORPLUS_HPP
