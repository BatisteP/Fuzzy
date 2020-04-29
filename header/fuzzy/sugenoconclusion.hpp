//
// Created by bp71 on 27/04/2020.
//

#ifndef SUGENO_CONCLUSION_HPP
#define SUGENO_CONCLUSION_HPP


#include "core/naryexpression.hpp"

namespace fuzzy {
    template<class T>
class SugenoConclusion : public core::NaryExpression<T> {
    public:
        SugenoConclusion(std::vector<T>* );

        virtual ~SugenoConclusion() {};

        virtual T evaluate(std::vector<const core::Expression<T>*>* operands) const;

    private:
        const std::vector <T> *coeff;
    };

    template<class T>
    T SugenoConclusion<T>::evaluate(std::vector<const core::Expression<T> *> *operands) const {
        typename std::vector<T>::const_iterator itcoef = coeff->begin();
        typename std::vector<const core::Expression<T>*>::const_iterator itexpr = operands->begin();
        T z = 0;

        // calcul de la somme des zi
        while( itexpr != operands->end() && itcoef != coeff->end())
        {
            T eval = (*itexpr)->evaluate();
            z += (*itcoef) * eval;
            itexpr++;
            itcoef++;
        }

        return z;
    }

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T>* coefficients):
        coeff(coefficients) {}


}
#endif //SUGENO_CONCLUSION_HPP
