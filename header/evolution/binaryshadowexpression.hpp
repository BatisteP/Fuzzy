#ifndef BINARYSHADOWEXPRESSION_HPP
#define BINARYSHADOWEXPRESSION_HPP

#include <iostream>
#include <core/binaryexpression.hpp>

namespace evolution {
    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>  {
    public:
        BinaryShadowExpression();
        virtual ~BinaryShadowExpression();

        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        virtual void setTarget(BinaryExpression<T>* );

    private:
        BinaryExpression<T>* target;
    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression() : BinaryExpression<T>() {}

    template <class T>
    BinaryShadowExpression<T>::~BinaryShadowExpression() {
        if (target != nullptr) {
            delete target;              /*!< Release the address pointed to by the pointer */
        }

        target = nullptr;               /*!< Delete pointer */
    }

    template <class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T> * l, Expression<T> * r) const {
        if (target == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        return target->evaluate(l, r);
    }

    template <class T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T> * o) {
        target = o;
    }
}

#endif // ! BINARYSHADOWEXPRESSION_HPP
