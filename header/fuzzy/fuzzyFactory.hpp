//
// Created by bp71 on 03/02/2020.
//

#ifndef SUGENO_FUZZYFACtory_HPP
#define SUGENO_FUZZYFACtory_HPP

#include <core/expressionFactory.hpp>
#include <fuzzy/and.hpp>
#include <fuzzy/not.hpp>
#include <fuzzy/or.hpp>
#include <fuzzy/agg.hpp>
#include <fuzzy/then.hpp>
#include <fuzzy/is.hpp>
#include <evolution/naryshadowexpression.hpp>
#include <fuzzy/is.hpp>
#include <evolution/unaryshadowexpression.hpp>
#include <evolution/binaryshadowexpression.hpp>


#include "mamdanidefuzz.hpp"
#include "sugenodefuzz.hpp"
#include "sugenoconclusion.hpp"

namespace fuzzy{
    template <class T>
    class FuzzyFactory: public core::ExpressionFactory<T>{
    public:

        // constructeur valué à (re)faire
        FuzzyFactory(And<T>*, Not<T>*, Agg<T>*, Or<T>*, Then<T>*, MamdaniDefuzz<T>*);
        FuzzyFactory(And<T>*, Not<T>*, Agg<T>*, Or<T>*, Then<T>*, SugenoDefuzz<T>*, SugenoConclusion<T>*);
        ~FuzzyFactory();


        core::Expression<T>* newAnd(core::Expression<T>*,core::Expression<T>*);
        core::Expression<T>* newNot(core::Expression<T>*);
        core::Expression<T>* newOr(core::Expression<T>*,core::Expression<T>*);
        core::Expression<T>* newIs(core::Expression<T>*,Is<T>*);
        core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*, const T& min, const T& max, const T& step);
        core::Expression<T>* newSugeno(std::vector<const core::Expression<T>*>*);
        core::Expression<T>* newSConclusion(std::vector<const core::Expression<T>*>*);

        void changeAnd(And<T>*);
        void changeNot(Not<T>*);
        void changeOr(Or<T>*);
        void changeThen(Then<T>*);
        void changeDefuzz(MamdaniDefuzz<T>*);
        void changeSugeno(SugenoDefuzz<T>*);
        void changeSConclusion(SugenoConclusion<T>*);
        void changeAgg(Agg<T>*);

    private:

        evolution::UnaryShadowExpression<T>  theNot;
        evolution::BinaryShadowExpression<T> theAnd;
        evolution::BinaryShadowExpression<T> theOr;
        evolution::BinaryShadowExpression<T> theThen;
        evolution::BinaryShadowExpression<T> theAgg;
        evolution::BinaryShadowExpression<T> mamdaniDefuzz;
        evolution::NaryShadowExpression<T>   sugeno;
        evolution::NaryShadowExpression<T>  conclusion;
        int k;







    };
    template<class T>
    FuzzyFactory<T>::FuzzyFactory (And<T> *_and, Not<T> *_not, Agg<T> *_agg, Or<T>* _or, Then <T>* _then,SugenoDefuzz<T> * _defuzz, SugenoConclusion<T>* _concl):
            theNot(_not),
            theAnd(_and),
            theOr(_or),
            theThen(_then),
            theAgg(_agg),
            mamdaniDefuzz(NULL),
            sugeno(_defuzz),
            conclusion(_concl)
    {

    }
    template<class T>
    FuzzyFactory
            <T>::FuzzyFactory
            (And<T> *_and, Not<T> *_not, Agg<T> *_agg, Or<T>* _or, Then <T>* _then, MamdaniDefuzz<T> * _defuzz):
            theNot(_not),
            theAnd(_and),
            theOr(_or),
            theThen(_then),
            theAgg(_agg),
            mamdaniDefuzz(_defuzz)
    {
    }



    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newAnd(core::Expression<T>* left, core::Expression<T>* right) {
        return this -> newBinary(&theAnd, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newNot(core::Expression<T>* exp) {
        return this -> newUnary(&theNot, exp);
    }


    template<class T>
    void FuzzyFactory
            <T>::changeAnd(And<T> *ope) {
        theAnd.setTarget(ope);
    }

    template<class T>
    void FuzzyFactory
            <T>::changeNot(Not <T>* ope) {
        theNot.setTarget(ope);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newOr(core::Expression<T> *left, core::Expression<T> *right) {
        return this -> newBinary(&theOr, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newIs(core::Expression<T> * op, Is<T>* is ) {
        return this ->newUnary( is, op);
    }





    template<class T>
    void FuzzyFactory
            <T>::changeOr(Or<T> *ope) {
        theOr.setTarget(ope);
    }

    template<class T>
    void FuzzyFactory
            <T>::changeThen(Then<T> *ope) {
        theThen.setTarget(ope);
    }

    template<class T>
    void FuzzyFactory
            <T>::changeAgg(Agg<T> *ope) {
        theAgg.setTarget(ope);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newThen(core::Expression<T> *left, core::Expression<T> *right) {
        return this ->newBinary(&theThen, left, right);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newAgg(core::Expression<T> *left, core::Expression<T> *right) {
        return this ->newBinary(&theAgg, left, right);
    }

    template<class T>
    FuzzyFactory
            <T>::~FuzzyFactory
            () {
        theNot = NULL;
        theAnd = NULL;
        theOr = NULL;
        theThen = NULL;
        theAgg = NULL;
        mamdaniDefuzz = NULL;
        sugeno = NULL;
        conclusion = NULL;

    }

    template<class T>
    core::Expression<T> *
    FuzzyFactory
            <T>::newDefuzz(core::Expression<T> * left, core::Expression<T> * right, const T &min, const T &max,
                           const T &step) {
        auto* target = (MamdaniDefuzz<T>*) mamdaniDefuzz.getTarget();
        target->setMin(min);
        target->setMax(max);
        target->setStep(step);
        return this -> newBinary(&mamdaniDefuzz, left , right);
    }

    template<class T>
    void FuzzyFactory
            <T>::changeDefuzz(MamdaniDefuzz<T> *ope) {
        mamdaniDefuzz.setTarget(ope);
    }



    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newSugeno(std::vector<const core::Expression<T> *> *operands) {
        return this -> newNary(&sugeno, operands);
    }

    template<class T>
    core::Expression<T> *FuzzyFactory
            <T>::newSConclusion(std::vector<const core::Expression<T> *> *operands) {
        return this -> newNary(&conclusion,operands);
    }

    template<class T>
    void FuzzyFactory
            <T>::changeSugeno(SugenoDefuzz<T> * s) {
        sugeno.setTarget(s);
    }

    template<class T>
    void FuzzyFactory<T>::changeSConclusion(SugenoConclusion<T> *s) {
        conclusion.setTarget(s);
    }




}


#endif //SUGENO_FUZZYFACTORY// _HPP
