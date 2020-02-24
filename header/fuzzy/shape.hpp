//
// Created by bp71 on 24/02/2020.
//

#ifndef SUGENO_SHAPE_HPP
#define SUGENO_SHAPE_HPP
//shape est une classe composée d'une liste d'abscisse et d'ordonnées (de même taille)

#include <list>
#include <core/valuemodel.hpp>

namespace fuzzy {
    template<class T>
    class Shape {
    public:
        Shape();

        Shape(std::list<T> _xs, std::list<T> _ys);

        void
        makeShape(const T &min, const T &max, const T &step, core::ValueModel<T> *value, core::Expression<T> *operat);

        std::ostream &print(std::ostream &) const;

    private:
        std::list<T> xs;
        std::list<T> ys;

    };

    template<class T>
    Shape<T>::Shape(std::list<T> _xs, std::list<T> _ys):
            xs(_xs), ys(_ys) {
    }

    template<class T>
    void Shape<T>::makeShape(const T &min, const T &max, const T &step, core::ValueModel<T> *value,
                             core::Expression<T> *operat) {
        T mem = value->Evaluate();

        for (T i = min; i <= max; i += step) {
            value->SetValue(i);
            xs.add(i);
            ys.add(operat->Evaluate());
        }

        value->SetValue(mem);

    }


    template<class T>
    Shape<T>::Shape() {

    }
        // todo trouver systeme pour afficher la shape (list de x et y)
    template<class T>
    std::ostream &Shape<T>::print(std::ostream & os) const {
        os << "todo";

    }
}
#endif //SUGENO_SHAPE_HPP
