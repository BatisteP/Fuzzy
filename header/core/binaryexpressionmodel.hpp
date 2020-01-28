#ifndef BINARYEXPRESSIONMODEL_HPP
#define BINARYEXPRESSIONMODEL_HPP

#include <iostream>
#include <core/binaryexpression.hpp>

namespace core {
    template <class T>
    class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
    public:
        BinaryExpressionModel();
        virtual ~BinaryExpressionModel();

        virtual T evaluate() const;
        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        virtual void setLeft(Expression<T>* );
        virtual void setRight(Expression<T>* );
        virtual void setOperator(BinaryExpression<T>* );

    private:
        Expression<T>* _left;
        Expression<T>* _right;
        BinaryExpression<T>* _operator;
    };

    template <class T>
    BinaryExpressionModel<T>::BinaryExpressionModel() {}

    template <class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel() {
        if (_left != nullptr) {
            delete _left;               /*!< Release the address pointed to by the pointer */
        }

        if (_right != nullptr) {
            delete _right;              /*!< Release the address pointed to by the pointer */
        }

        if (_operator != nullptr) {
            delete _operator;           /*!< Release the address pointed to by the pointer */
        }

        _left = nullptr;                /*!< Delete pointer */
        _right = nullptr;               /*!< Delete pointer */
        _operator = nullptr;            /*!< Delete pointer */
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate() const {
        if (_left == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        if (_right == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        return evaluate(_left, _right);
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
        if (_operator == nullptr) {
            throw exceptions::NullPointerException<T>("null operator");
        }
        return _operator->evaluate(l, r);
    }

    template <class T>
    void BinaryExpressionModel<T>::setLeft(Expression<T>* o) {
        _left = o;
    }

    template <class T>
    void BinaryExpressionModel<T>::setRight(Expression<T>* o) {
        _right = o;
    }

    template <class T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>* o) {
        _operator = o;
    }
}

#endif // ! BINARYEXPRESSIONMODEL_HPP
