#ifndef VALUEMODEL_HPP
#define VALUEMODEL_HPP

#include <iostream>
#include <core/expression.hpp>

namespace core {
    template <class T>
    class ValueModel : public Expression<T> {
    public:
        ValueModel();
        ValueModel(const T& v);
        virtual ~ValueModel();

        virtual T evaluate() const;
        virtual void setValue(T);

    private:
        T value;
    };

    template <class T>
    ValueModel<T>::ValueModel() : Expression<T>() {}

    template <class T>
    ValueModel<T>::~ValueModel() {}

    template <class T>
    T ValueModel<T>::evaluate() const {
        return value;
    }

    template <class T>
    void ValueModel<T>::setValue(T _value) {
        value = _value;
    }

    template<class T>
    ValueModel<T>::ValueModel(const T &_value) :
    value(_value){

    }
}

#endif // ! VALUEMODEL_HPP
