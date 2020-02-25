//
// Created by bp71 on 24/02/2020.
//

#ifndef SUGENO_SHAPE_HPP
#define SUGENO_SHAPE_HPP
//shape est une classe composée d'une liste d'abscisse et d'ordonnées (de même taille)

#include <list>
#include <core/valuemodel.hpp>
#include <vector>

namespace fuzzy {
    template<class T>
    class Shape {
    public:
        Shape();

        Shape(std::vector<T> _xs, std::vector<T> _ys);

        void makeShape(const T &min, const T &max, const T &step, core::ValueModel<T> *value, core::Expression<T> *operat);
        std::vector<T> getXs() const;
        std::vector<T> getYs() const;
        std::ostream &print(std::ostream &) const;

    private:
        std::vector<T> xs;
        std::vector<T> ys;

    };

    template<class T>
    Shape<T>::Shape(std::vector<T> _xs, std::vector<T> _ys):
            xs(_xs), ys(_ys) {
    }

    template<class T>
    void Shape<T>::makeShape(const T &min, const T &max, const T &step, core::ValueModel<T> *value,
                             core::Expression<T> *operat) {
        T mem = value->evaluate();

        for (T i = min; i <= max; i += step) {
            value->setValue(i);
            xs.push_back(i);
            ys.push_back(operat->evaluate());
        }

        value->setValue(mem);

    }


    template<class T>
    Shape<T>::Shape() {

    }
        // todo trouver systeme pour afficher la shape (list de x et y)
    template<class T>
    std::ostream &Shape<T>::print(std::ostream & os) const {
        os << "todo";
        return os;
    }

    template<class T>
    std::vector<T> Shape<T>::getXs() const {
        return xs;
    }

    template<class T>
    std::vector<T> Shape<T>::getYs() const{
       return ys;
    }
}
#endif //SUGENO_SHAPE_HPP
