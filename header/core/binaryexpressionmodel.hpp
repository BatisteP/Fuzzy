#ifndef BINARYEXPRESSIONMODEL_HPP
#define BINARYEXPRESSIONMODEL_HPP

#include <iostream>
#include <core/binaryexpression.hpp>

namespace core {
    template <class T>
    class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
    public:
        BinaryExpressionModel();
        BinaryExpressionModel(Expression<T>*, Expression<T>*);
        BinaryExpressionModel(Expression<T>*, Expression<T>*, BinaryExpression<T>*);
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
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r)
            : Expression<T>(), BinaryExpression<T>(), _left(l), _right(r), _operator(nullptr) {}

    template <class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T>* o)
            : Expression<T>(), BinaryExpression<T>(), _left(l), _right(r), _operator(o) {}

    template <class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel() {};

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
    void BinaryExpressionModel<T>::setLeft(Expression<T>* l) {
        if (l == nullptr) {
            throw exceptions::NullPointerException<T>("null left operand");
        }

        _left = l;
    }

    template <class T>
    void BinaryExpressionModel<T>::setRight(Expression<T>* r) {
        if (r == nullptr) {
            throw exceptions::NullPointerException<T>("null right operand");
        }

        _right = r;
    }

    template <class T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>* o) {
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operator");
        }

        _operator = o;
    }
}

#endif // ! BINARYEXPRESSIONMODEL_HPP
