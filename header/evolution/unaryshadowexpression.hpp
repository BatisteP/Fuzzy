#ifndef UNARYSHADOWEXPRESSION_HPP
#define UNARYSHADOWEXPRESSION_HPP

#include <iostream>
#include <core/unaryexpression.hpp>

namespace evolution {
    template <class T>
    class UnaryShadowExpression : public core::UnaryExpression<T> {
    public:
        UnaryShadowExpression(core::UnaryExpression<T>*);
        virtual ~UnaryShadowExpression();

        virtual T evaluate(core::Expression<T>*);
        virtual void setTarget(core::UnaryExpression<T>*);

    private:
        core::UnaryExpression<T>* target;
    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(core::UnaryExpression<T> * _target)
        : core::UnaryExpression<T>(), target(_target) {}

    template <class T>
    UnaryShadowExpression<T>::~UnaryShadowExpression() {}

    template <class T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> * o) {
        if (target == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        return target->evaluate(o);
    }

    template <class T>
    void UnaryShadowExpression<T>::setTarget(core::UnaryExpression<T> * o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        target = o;
    }
}

#endif // ! UNARYSHADOWEXPRESSION_HPP
