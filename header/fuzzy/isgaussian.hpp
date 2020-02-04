#ifndef ISGAUSSIAN_HPP
#define ISGAUSSIAN_HPP

#include <iostream>
#include <exceptions/standarddeviationexception.hpp>
#include <fuzzy/is.hpp>
#include <cmath>

namespace fuzzy {
    template <class T>
    class IsGaussian : public Is<T> {
    public:
        IsGaussian(T, T);
        virtual ~IsGaussian();

        virtual T evaluate(core::Expression<T>*) const;
        virtual void setDeviation(T);
        virtual void setAverage(T);

    private:
        T deviation;
        T average;
    };

    template <class T>
    IsGaussian<T>::IsGaussian(T _average, T _deviation)
        : deviation(_deviation), average(_average) {}

    template <class T>
    IsGaussian<T>::~IsGaussian() {}

    template <class T>
    void IsGaussian<T>::setDeviation(T _deviation) {
        // TODO : if (k <= 0) where k = deviation launch exception
        if (_deviation <= 0) {
            throw exceptions::StandardDeviationException<T>("Standard deviation lower equal than zero, i.e : deviation <= 0")
        }

        deviation = _deviation;
    }

    template <class T>
    void IsGaussian<T>::setAverage(T _average) {
        average = _average;
    }

    template <class T>
    T IsGaussian<T>::evaluate(core::Expression<T> * o) const {
        // TODO : if operand is a null pointer launch exception
        if (o == nullptr) {
            throw exceptions::NullPointerException<T>("null operand");
        }

        // TODO : where m = average and k = deviation > 0
        if (deviation <= 0) {
            throw exceptions::StandardDeviationException<T>("Standard deviation lower equal than zero");
        }

        // TODO : Getting x
        T xValue = o->evaluate();

        // TODO : exp(-(x - m)^2 / 2*k^2)
        // ça c'est beau
        return (T) exp(-(xValue - average) * (xValue - average) / (2 * deviation * deviation));
    }
}

#endif // ! ISGAUSSIAN_HPP
