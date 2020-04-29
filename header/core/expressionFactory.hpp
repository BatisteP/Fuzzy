//
// Created by bp71 on 03/02/2020.
//
#include "expression.hpp"
#include "unaryexpressionmodel.hpp"
#include "binaryexpressionmodel.hpp"
#include "naryexpressionmodel.hpp"
#include <list>

#ifndef SUGENO_EXPRESSIONFACTORY_HPP
#define SUGENO_EXPRESSIONFACTORY_HPP
namespace core{
    template <class T>
    class ExpressionFactory{
    public:
        typedef  std::list<Expression<T>*> e_list;
        typedef typename e_list::iterator iterator;
        ExpressionFactory(){};
        ~ExpressionFactory();
        UnaryExpressionModel<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
        BinaryExpressionModel<T>* newBinary(BinaryExpression<T>*, Expression<T>*,Expression<T>*);
        NaryExpressionModel<T>* newNary(NaryExpression<T>*, std::vector<const Expression<T>*>*);
        Expression<T>* hold(Expression<T>*);
    private:
        e_list memory;
    };

    template<class T>
    Expression<T> *ExpressionFactory<T>::hold(Expression<T> * exp) {
       memory.push_back(exp);
       return exp;
    }



    template<class T>
    ExpressionFactory<T>::~ExpressionFactory() {
        //expressionList.clear();
        iterator it = memory.begin();
        while(it != memory.end()) {
            delete *it;
            it++;
            std::cout << "objet detruit";
        }
        memory.clear();


    }

    template<class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* left,Expression<T>* right) {
        BinaryExpressionModel<T>* obj = new BinaryExpressionModel<T>(left, right, ope);
        hold(obj);
        return obj;
    }

    template<class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o) {
        UnaryExpressionModel<T>* obj = new UnaryExpressionModel<T>(o, ope);
        hold(obj);
        return obj;
    }

    template <class T>
    NaryExpressionModel<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* operateur, std::vector<const Expression<T>*>* operands)
    {
        NaryExpressionModel<T>* obj = new NaryExpressionModel<T>(operateur, operands);
        hold(obj);
        return obj;
    }
}


#endif //SUGENO_EXPRESSIONFACTORY_HPP
