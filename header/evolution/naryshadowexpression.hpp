#ifndef NARYSHADOWEXPRESSION_HPP
#define NARYSHADOWEXPRESSION_HPP

#include <iostream>
#include <core/binaryexpression.hpp>
#include <core/naryexpression.hpp>

namespace evolution {
    template <class T>
class NaryShadowExpression : public core::NaryExpression<T>  {
    public:
        NaryShadowExpression( ){};
        NaryShadowExpression(core::NaryExpression<T>* );
        virtual ~NaryShadowExpression();

        T evaluate(std::vector<const core::Expression<T>*>* operands) const;
        void setTarget(core::NaryExpression<T>* );
        virtual core::NaryExpression<T>* getTarget();

private:
        core::NaryExpression<T>* target;
    };

    template <class T>
    NaryShadowExpression<T>::NaryShadowExpression(core::NaryExpression<T>* _target)
        : core::NaryExpression<T>(), target(_target) {}

    template <class T>
   NaryShadowExpression<T>::~NaryShadowExpression() {}

    template <class T>
    T NaryShadowExpression<T>::evaluate(std::vector<const core::Expression<T>*>* operands) const {
        if (target == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        return target->evaluate(operands);
    }

    template <class T>
    void NaryShadowExpression<T>::setTarget(core::NaryExpression<T> * o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null target");
        }

        target = o;
    }

    template<class T>
    core::NaryExpression<T> *NaryShadowExpression<T>::getTarget() {
        return target;
    }
}

#endif // ! NARYSHADOWEXPRESSION_HPP
