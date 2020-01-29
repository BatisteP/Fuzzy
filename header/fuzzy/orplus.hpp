#ifndef ORPLUS_HPP
#define ORPLUS_HPP

#include <iostream>
#include <fuzzy/or.hpp>

namespace fuzzy {
    template <class T>
    class OrPlus : public Or<T> {
    public:
        T evaluate(core::Expression<T>*, core::Expression<T>* ) const;
    };
}

#endif // ! ORPLUS_HPP
