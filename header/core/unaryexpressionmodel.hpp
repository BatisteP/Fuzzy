#ifndef UNARYEXPRESSIONMODEL_HPP
#define UNARYEXPRESSIONMODEL_HPP

#include <iostream>
#include <core/unaryexpression.hpp>

namespace core {
    template <class T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T> {
    public:
        UnaryExpressionModel(Expression<T>*, UnaryExpression<T>*);
        virtual ~UnaryExpressionModel();

        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* ) const;
        virtual void setOperand(Expression<T>* );
        virtual void setOperator(UnaryExpression<T>* );

    private:
        Expression<T>* _operand;
        UnaryExpression<T>* _operator;
    };

    template <class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* operators)
            : Expression<T>(), UnaryExpression<T>(), _operand(operand), _operator(operators) {}

    template <class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel() {}

    template <class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if (_operand == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        return evaluate(_operand);
    }

    template <class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const {
        if (_operator == nullptr) {
            throw exceptions::NullPointerException<T>("null operator");
        }

        return _operator->evaluate(o);
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperand(core::Expression<T>* o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        _operand = o;
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operator");
        }

        _operator = o;
    }
}

#endif // ! UNARYEXPRESSIONMODEL_HPP
