#ifndef UNARYEXPRESSIONMODEL_HPP
#define UNARYEXPRESSIONMODEL_HPP

#include <iostream>
#include <core/unaryexpression.hpp>

namespace core {
    template <class T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T> {
    public:
        UnaryExpressionModel();
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
    UnaryExpressionModel<T>::UnaryExpressionModel()
            : Expression<T>(), UnaryExpression<T>() {}

    template <class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel() {
        if (_operand != nullptr) {
            delete _operand;            /*!< Release the address pointed to by the pointer */
        }

        if (_operator != nullptr) {
            delete _operator;           /*!< Release the address pointed to by the pointer */
        }

        _operand = nullptr;             /*!< Delete pointer */
        _operator = nullptr;            /*!< Delete pointer */
    }

    template <class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if (_operand == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }
        return _operand->evaluate();
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
        _operand = o;
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* o) {
        _operator = o;
    }
}

#endif // ! UNARYEXPRESSIONMODEL_HPP
