//
// Created by bp71 on 18/02/2020.
//

#ifndef SUGENO_NARYEXPRESSIONMODEL_HPP
#define SUGENO_NARYEXPRESSIONMODEL_HPP

#include <iostream>
#include <core/expression.hpp>
#include <exceptions/nullpointerexception.hpp>
#include <vector>
#include "naryexpression.hpp"

namespace core {
    template <class T>
class NaryExpressionModel :public NaryExpression<T>, public core::Expression<T>{
    public:
        NaryExpressionModel(){};
        virtual ~NaryExpressionModel(){};
    NaryExpressionModel(NaryExpression<T>*, std::vector<const core::Expression<T>*>* );
        T evaluate() const;
        T evaluate(std::vector<const core::Expression<T>*>*) const;
    private:
        NaryExpression<T>* ope;
        std::vector<const core::Expression<T>*>* opeVect;
    };

    template<class T>
    T NaryExpressionModel<T>::evaluate() const {
        if (opeVect->size() == 0)
            throw new exceptions::NullPointerException<T>("opeVect empty");

        return evaluate(opeVect);
    }

    template<class T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression <T> *_ope, std::vector<const core::Expression<T> *> * _opeVect) :
            ope(_ope), opeVect(_opeVect){

    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(std::vector<const core::Expression<T> *>* _opeVect) const {
        if (_opeVect == NULL )
            throw new exceptions::NullPointerException<T>("vecteur d'operandes null ou vide");

        return ope->evaluate(_opeVect);
    }



}

#endif //SUGENO_NARYEXPRESSIONMODEL_HPP
