#include <iostream>
#include <core/valuemodel.hpp>
#include <core/binaryexpressionmodel.hpp>
#include <core/unaryexpressionmodel.hpp>
#include <fuzzy/andmin.hpp>
#include <fuzzy/andmult.hpp>
#include <fuzzy/istriangle.hpp>
#include <evolution/binaryshadowexpression.hpp>

int main() {
    core::ValueModel<float> v1;
    v1.setValue(33);

    core::ValueModel<float> v2;
    v2.setValue(3);
    core::ValueModel<float> v3;
    v3.setValue(6);
    fuzzy::AndMin<float> andMinOp;
    fuzzy::AndMult<float> andMaxOp;
    fuzzy::IsTriangle<float> triangle(2.0,5,12.0);
    core::BinaryExpressionModel<float> bModel(&v2,&v3,&andMinOp);

    core::UnaryExpressionModel<float> uModel(&v2,&triangle);


    std ::cout  << "test opérateurs" << std :: endl;
    std ::cout  << "triangle (2,5,12), evaluate avec 3, puis avec 6 " << std :: endl;

    uModel.setOperator(&triangle);
    //unarymodel test
    std ::cout  << uModel.evaluate(&v2) << std :: endl;
    std ::cout  << uModel.evaluate(&v3) << std :: endl;
    std ::cout  << "andMult 3,6 " << std :: endl;
//    bModel.setOperator()
    std ::cout  << "andMin 3,6 " << std :: endl;
    std ::cout  << "OrPlus 3,6 " << std :: endl;
    std ::cout  << "OrMax 3,6 " << std :: endl;
    std::cout << v1.evaluate() << std::endl;

    return 0;

}