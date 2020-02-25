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
         T defuzz(const Shape<T> &) const;

    };

    template<class T>
    T CogDefuzz<T>::defuzz(const Shape<T> &s) const {
        // todo renvoie le barycentre/ centre de gravité de la shape
        std::vector<T> xs =  s.getXs();
        std::vector<T> ys = s.getYs();


        //valeur du barycentre = (sum (xs * ys))/(sum ys) (cf wikipédia)
        float sumxsys = 0;
        float sumys = 0;
        for (unsigned int i = 0; i< xs.size(); i++){

            sumxsys += xs[i]*ys[i];
            sumys += ys[i];


        }
        return sumxsys/sumys;

    }
}
#endif //SUGENO_COGDEFUZZ_HPP
