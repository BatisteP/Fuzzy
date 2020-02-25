//
// Created by bp71 on 24/02/2020.
//

#ifndef SUGENO_MAMDANIDEFUZZ_HPP
#define SUGENO_MAMDANIDEFUZZ_HPP

#include <core/expression.hpp>
#include <core/valuemodel.hpp>
#include "shape.hpp"
#include <core/binaryexpression.hpp>
namespace fuzzy {
    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T> {
    public:

        MamdaniDefuzz(){};
        MamdaniDefuzz(const T &_min, const T &_max, const T &_step);

        ~MamdaniDefuzz() {};

        void setMin(const T &_min);

        void setMax(const T &_max);

        void setStep(const T &_step);

         T evaluate(core::Expression<T> *, core::Expression<T> *) const;
         virtual T defuzz(const Shape<T> &) const = 0;

    private:
        T min, max, step;
    };

    template<class T>
    void MamdaniDefuzz<T>::setMin(const T &_min) {
        min = _min;
    }

    template<class T>
    void MamdaniDefuzz<T>::setMax(const T &_max) {
        max = _max;
    }

    template<class T>
    void MamdaniDefuzz<T>::setStep(const T &_step) {
        step = _step;
    }

    template<class T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T> *value, core::Expression<T> *operat) const {
        Shape<T> s;
        s.makeShape(min, max, step, (core::ValueModel<T> *) value, operat);
        return defuzz(s);
    }

    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T &_min, const T &_max, const T &_step) :
            min(_min), max(_max), step(_step) {

    }
}
#endif //SUGENO_MAMDANIDEFUZZ_HPP
