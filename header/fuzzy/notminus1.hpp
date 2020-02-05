#ifndef NOTMINUS1_HPP
#define NOTMINUS1_HPP

#include <iostream>
#include <fuzzy/not.hpp>

namespace fuzzy {
    template <class T>
    class NotMinus1 : public Not<T> {
    public:
        virtual T evaluate(core::Expression<T>* ) const;
    };

    template <class T>
    T NotMinus1<T>::evaluate(core::Expression <T> * o) const {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        return (1 - o->evaluate());
    }
}

#endif // ! NOTMINUS1_HPP
