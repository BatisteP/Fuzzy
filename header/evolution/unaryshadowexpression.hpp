#ifndef UNARYSHADOWEXPRESSION_HPP
#define UNARYSHADOWEXPRESSION_HPP

#include <iostream>
#include <core/unaryexpression.hpp>

namespace evolution {
    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public:
        UnaryShadowExpression();
        UnaryShadowExpression(UnaryExpression<T>*);
        virtual ~UnaryShadowExpression();

        virtual T evaluate(Expression<T>*);
        virtual void setTarget(UnaryExpression<T>*);

    private:
        UnaryExpression<T>* target;
    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression()
        : UnaryExpression<T>(), target(nullptr) {}

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression <T> * _target)
        : UnaryExpression<T>(), target(_target) {}

    template <class T>
    UnaryShadowExpression<T>::~UnaryShadowExpression() {}

    template <class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T> * o) {
        if (target == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        return target->evaluate(o);
    }

    template <class T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> * o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        target = o;
    }
}

#endif // ! UNARYSHADOWEXPRESSION_HPP
