//
// Created by bp71 on 24/02/2020.
//
#include "mamdanidefuzz.hpp"
#ifndef SUGENO_COGDEFUZZ_HPP
#define SUGENO_COGDEFUZZ_HPP
namespace fuzzy {
    template<class T>
    class CogDefuzz : public MamdaniDefuzz<T> {
    public:
        CogDefuzz() {};

        ~CogDefuzz() {};

    protected:
        virtual T Defuzz(const Shape<T> &) const;
    };

    template<class T>
    T CogDefuzz<T>::Defuzz(const Shape<T> &) const {
        // todo renvoie le barycentre/ centre de gravité de la shape
        return nullptr;
    }
}
#endif //SUGENO_COGDEFUZZ_HPP
