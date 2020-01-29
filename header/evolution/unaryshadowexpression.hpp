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

        virtual T evaluate(Expression<T>* );
        virtual void setTarget(UnaryExpression<T>* );

    private:
        UnaryExpression<T>* target;
    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression() : UnaryExpression<T>() {}

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression <T> * _target)
        : UnaryExpression<T>(), target(_target) {}

    template <class T>
    UnaryShadowExpression<T>::~UnaryShadowExpression() {
        if (target != nullptr) {
            delete target;               /*!< Release the address pointed to by the pointer */
        }

        target = nullptr;               /*!< Delete pointer */
    }

    template <class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T> * o) {
        if (target == nullptr) {
            throw exceptions::NullPointerException("null target");
        }

        return target->evaluate(o);
    }

    template <class T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> * o) {
        target = o;
    }
}

#endif // ! UNARYSHADOWEXPRESSION_HPP
