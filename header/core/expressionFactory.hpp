//
// Created by bp71 on 03/02/2020.
//
#include "expression.hpp"
#include "unaryexpressionmodel.hpp"
#include "binaryexpressionmodel.hpp"
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
        UnaryExpressionModel<T>* NewUnary(UnaryExpression<T>*, Expression<T>*);
        BinaryExpressionModel<T>* NewBinary(BinaryExpression<T>*, Expression<T>*,Expression<T>*);
        Expression<T>* Hold(Expression<T>*);
    private:
        e_list memory;
    };

    template<class T>
    Expression<T> *ExpressionFactory<T>::Hold(Expression<T> * exp) {
       memory.insert(exp);
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
        delete memory;

    }

    template<class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::NewBinary(BinaryExpression<T>* ope, Expression<T>* left,Expression<T>* right) {
        BinaryExpressionModel<T> obj = new BinaryExpressionModel<T>(ope,left, right);
        Hold(obj);
        return obj;
    }

    template<class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::NewUnary(UnaryExpression<T>* ope, Expression<T>* o) {
        UnaryExpressionModel<T> obj = new UnaryExpressionModel<T>(ope, o);
        Hold(obj);
        return obj;
    }
}

}
#endif //SUGENO_EXPRESSIONFACTORY_HPP
