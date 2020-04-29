//
// Created by bp71 on 27/04/2020.
//

#ifndef SUGENO_DEFUZZ_HPP
#define SUGENO_DEFUZZ_HPP


#include <evolution/binaryshadowexpression.hpp>
#include "core/naryexpression.hpp"
#include "fuzzy/sugenothen.hpp"
namespace fuzzy {
    template<class T>
class SugenoDefuzz : public core::NaryExpression<T> {
    public:
        SugenoDefuzz(){};
        using core::NaryExpression<T>::evaluate;
        virtual ~SugenoDefuzz() {};
        virtual T evaluate(std::vector<const core::Expression<T>*>* operands) const;

};

    template<class T>
    T SugenoDefuzz<T>::evaluate(std::vector<const core::Expression<T> *> *operands) const {
        typename std::vector<const core::Expression<T>*>::const_iterator it;

        T num = 0;
        T denum = 0;

        // calcul somme des wi
        for (it = operands->begin(); it != operands->end(); it++)
        {
            core::BinaryExpressionModel<T>*  bem = (core::BinaryExpressionModel<T>*)  (*it);
            evolution::BinaryShadowExpression<T>* bse = (evolution::BinaryShadowExpression<T>*) bem->getOperateur();
            SugenoThen<T>*                   sth = (SugenoThen<T>*)                   bse->getTarget();

            num   += (*it)->evaluate();
            denum += sth->getPremiseValue();
        }

        if (denum != 0)
            return num/denum;
        else
            return 0;
    }

}


#endif //SUGENO_DEFUZZ_HPP
