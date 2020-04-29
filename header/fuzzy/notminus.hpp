#ifndef NOTMINUS_HPP
#define NOTMINUS_HPP

#include <iostream>
#include <fuzzy/not.hpp>

namespace fuzzy {
    template <class T>
    class NotMinus : public Not<T> {
    public:
        virtual T evaluate(core::Expression<T>* ) const;
    };

    template <class T>
    T NotMinus<T>::evaluate(core::Expression <T> * o) const {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        return ( - o->evaluate());
    }
}

#endif // ! NOTMINUS_HPP
