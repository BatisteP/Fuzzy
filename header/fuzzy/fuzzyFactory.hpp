//
// Created by bp71 on 03/02/2020.
//

#ifndef SUGENO_FUZZYFACTORY_HPP
#define SUGENO_FUZZYFACTORY_HPP

#include <core/expressionFactory.hpp>
#include <fuzzy/and.hpp>
#include <fuzzy/not.hpp>
#include <evolution/binaryshadowexpression.hpp>
#include <evolution/unaryshadowexpression.hpp>

namespace fuzzy{
    template <class T>
    class FuzzyFactory: public core::ExpressionFactory<T>{
        public:
            FuzzyFactory(){};
            // constructeur valué à (re)faire
            FuzzyFactory(And<T>*, Not<T>*);

            ~FuzzyFactory();

            //un example unary et binary il faudra faire les autres
            core::Expression<T>* newAnd(core::Expression<T>*,core::Expression<T>*);
            core::Expression<T>* newNot(core::Expression<T>*);

            void changeAnd(And<T>*);
            void changeNot(Not<T>*);
        private:
            evolution::BinaryShadowExpression<T>* theAnd;
            evolution::UnaryShadowExpression<T>* theNot;





};

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory() {
        delete theAnd;
        delete theNot;
        // etc...
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newAnd(core::Expression<T>* left, core::Expression<T>* right) {
        return newBinary(theAnd, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newNot(core::Expression<T>* exp) {
        return newUnary(theNot, exp);
    }

    template<class T>
    void FuzzyFactory<T>::changeAnd(And<T> *ope) {
        theAnd->setTarget(ope);
    }

    template<class T>
    void FuzzyFactory<T>::changeNot(Not <T> *ope) {
        theNot->setTarget(ope);
    }

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T> * _not, Not<T> *_and) :
        theAnd(new evolution::BinaryShadowExpression<T>(_and)),
        theNot(new evolution::UnaryShadowExpression<T>(_not)){}


}
#endif //SUGENO_FUZZYFACTORY_HPP
