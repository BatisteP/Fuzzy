#ifndef BINARYSHADOWEXPRESSION_HPP
#define BINARYSHADOWEXPRESSION_HPP

#include <iostream>
#include <core/binaryexpression.hpp>

namespace evolution {
    template <class T>
class BinaryShadowExpression : public core::BinaryExpression<T>  {
    public:
        BinaryShadowExpression();
        BinaryShadowExpression(core::BinaryExpression<T>* );
        virtual ~BinaryShadowExpression();

        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        virtual void setTarget(core::BinaryExpression<T>* );

    private:
        core::BinaryExpression<T>* target;
    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression()
        : core::BinaryExpression<T>(), target(nullptr) {}

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(core::BinaryExpression<T>* _target)
        : core::BinaryExpression<T>(), target(_target) {}

    template <class T>
    BinaryShadowExpression<T>::~BinaryShadowExpression() {}

    template <class T>
    T BinaryShadowExpression<T>::evaluate(core::Expression<T> * l, core::Expression<T> * r) const {
        if (target == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        return target->evaluate(l, r);
    }

    template <class T>
    void BinaryShadowExpression<T>::setTarget(core::BinaryExpression<T> * o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        target = o;
    }
}

#endif // ! BINARYSHADOWEXPRESSION_HPP
