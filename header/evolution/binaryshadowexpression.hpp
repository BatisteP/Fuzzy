#ifndef BINARYSHADOWEXPRESSION_HPP
#define BINARYSHADOWEXPRESSION_HPP

#include <iostream>
#include <core/binaryexpression.hpp>

namespace evolution {
    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>  {
    public:
        BinaryShadowExpression();
        BinaryShadowExpression(BinaryExpression<T>* );
        virtual ~BinaryShadowExpression();

        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        virtual void setTarget(BinaryExpression<T>* );

    private:
        BinaryExpression<T>* target;
    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression() : BinaryExpression<T>() {}

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target)
        : BinaryExpression<T>(), target(_target) {}

    template <class T>
    BinaryShadowExpression<T>::~BinaryShadowExpression() {}

    template <class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T> * l, Expression<T> * r) const {
        if (target == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        return target->evaluate(l, r);
    }

    template <class T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T> * o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        target = o;
    }
}

#endif // ! BINARYSHADOWEXPRESSION_HPP
