#include <iostream>
#include <core/valuemodel.hpp>
#include <core/binaryexpressionmodel.hpp>
#include <fuzzy/andmin.hpp>

int main() {
    core::ValueModel<int>* v1 = new core::ValueModel<int>();
    core::ValueModel<int>* v2 = new core::ValueModel<int>();
    v1->setValue(33);
    v2->setValue(25);
    std::cout << "Value Model 1 : " << v1->evaluate() << std::endl;
    std::cout << "Value Model 2 : " << v2->evaluate() << std::endl;

    core::BinaryExpressionModel<int> b;
    fuzzy::AndMin<int>* andMin = new fuzzy::AndMin<int>();

    b.setLeft(v1);
    b.setRight(v2);
    b.setOperator(andMin);

    std::cout << "Evaluate : " << b.evaluate() << std::endl;
}