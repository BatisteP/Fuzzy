//
// Created by Yassine Sameh on 02/05/2020.
//

#ifndef SUGENO_ISSIGMOID_HPP
#define SUGENO_ISSIGMOID_HPP

#include <fuzzy/is.hpp>
#include <cmath>

namespace fuzzy {
    template <class T>
    class IsSigmoid : public Is<T> {
    public:
        IsSigmoid(T _min);
        virtual ~IsSigmoid();

        virtual T evaluate(core::Expression<T>*) const;
        virtual void setMin(T);

    private:
        T min;
    };

    template<class T>
    IsSigmoid<T>::IsSigmoid(T _min)
            : min(_min) {}

    template <class T>
    IsSigmoid<T>::~IsSigmoid() {}

    template <class T>
    void IsSigmoid<T>::setMin(T _min) {
        min = _min;
    }

    template <class T>
    T IsSigmoid<T>::evaluate(core::Expression<T>* o) const {
        return 1 / (1 + std::exp(-o->evaluate() - min));
    }
}

#endif //SUGENO_ISSIGMOID_HPP
