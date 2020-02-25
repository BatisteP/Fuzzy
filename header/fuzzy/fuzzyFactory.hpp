//
// Created by bp71 on 03/02/2020.
//

#ifndef SUGENO_FUZZYFACTORY_HPP
#define SUGENO_FUZZYFACTORY_HPP

#include <core/expressionFactory.hpp>
#include <fuzzy/and.hpp>
#include <fuzzy/not.hpp>
#include <fuzzy/or.hpp>
#include <fuzzy/agg.hpp>
#include <fuzzy/then.hpp>
#include <fuzzy/is.hpp>
#include <evolution/binaryshadowexpression.hpp>
#include <evolution/unaryshadowexpression.hpp>
#include "mamdanidefuzz.hpp"

namespace fuzzy{
    template <class T>
    class FuzzyFactory: public core::ExpressionFactory<T>{
        public:

            // constructeur valué à (re)faire
            FuzzyFactory(And<T>*, Not<T>*, Agg<T>*, Or<T>*, Then<T>*, MamdaniDefuzz<T>*);

            ~FuzzyFactory();


            core::Expression<T>* newAnd(core::Expression<T>*,core::Expression<T>*);
            core::Expression<T>* newNot(core::Expression<T>*);
            core::Expression<T>* newOr(core::Expression<T>*,core::Expression<T>*);
            core::Expression<T>* newIs(core::Expression<T>*,Is<T>*);
            core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
            core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
            core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*, const T& min, const T& max, const T& step);

            void changeAnd(And<T>*);
            void changeNot(Not<T>*);
            void changeOr(Or<T>*);
            void changeThen(Then<T>*);
            void changeDefuzz(MamdaniDefuzz<T>*);
            void changeAgg(Agg<T>*);

        private:

            evolution::BinaryShadowExpression<T> theAnd;
            evolution::UnaryShadowExpression<T> theNot;
        evolution::BinaryShadowExpression<T> theAgg;
            evolution::BinaryShadowExpression<T> theOr;
            evolution::BinaryShadowExpression<T> theThen;

            evolution::BinaryShadowExpression<T> mamdaniDefuzz;






};



    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newAnd(core::Expression<T>* left, core::Expression<T>* right) {
        return this -> newBinary(&theAnd, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newNot(core::Expression<T>* exp) {
        return this -> newUnary(&theNot, exp);
    }

    template<class T>
    void FuzzyFactory<T>::changeAnd(And<T> *ope) {
        theAnd.setTarget(ope);
    }

    template<class T>
    void FuzzyFactory<T>::changeNot(Not <T>* ope) {
        theNot.setTarget(ope);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newOr(core::Expression<T> *left, core::Expression<T> *right) {
        return this ->newBinary(&theOr, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newIs(core::Expression<T> * op, Is<T>* is ) {
        return this ->newUnary( is , op);
    }

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T> *_and, Not<T> *_not, Agg<T> *_agg, Or<T>* _or, Then <T>* _then, MamdaniDefuzz<T> * _defuzz)  :
        theAnd(_and),
        theNot(_not),
        theAgg(_agg),
        theOr(_or),
        theThen(_then),
        mamdaniDefuzz(_defuzz)

    {


    }

    template<class T>
    void FuzzyFactory<T>::changeOr(Or<T> *ope) {
        theOr.setTarget(ope);
    }

    template<class T>
    void FuzzyFactory<T>::changeThen(Then<T> *ope) {
        theThen.setTarget(ope);
    }

    template<class T>
    void FuzzyFactory<T>::changeAgg(Agg<T> *ope) {
        theAgg.setTarget(ope);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newThen(core::Expression<T> *left, core::Expression<T> *right) {
        return this ->newBinary(&theThen, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory<T>::newAgg(core::Expression<T> *left, core::Expression<T> *right) {
        return this ->newBinary(&theAgg, left, right);
    }

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory() {

    }

    template<class T>
    core::Expression<T> *
    FuzzyFactory<T>::newDefuzz(core::Expression<T> * left, core::Expression<T> * right, const T &min, const T &max,
                               const T &step) {
        auto* target = (MamdaniDefuzz<T>*) mamdaniDefuzz.getTarget();
        target->setMin(min);
        target->setMax(max);
        target->setStep(step);
        return this -> newBinary(&mamdaniDefuzz, left , right);
    }

    template<class T>
    void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T> *ope) {
        mamdaniDefuzz->setTarget(ope);
    }

}


#endif //SUGENO_FUZZYFACTORY_HPP
