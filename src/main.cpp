#include <iostream>
#include <core/valuemodel.hpp>
#include <core/binaryexpressionmodel.hpp>
#include <core/unaryexpressionmodel.hpp>
#include <fuzzy/andmin.hpp>
#include <fuzzy/andmult.hpp>
#include <fuzzy/istriangle.hpp>
#include <fuzzy/notminus1.hpp>
#include <fuzzy/ormax.hpp>
#include <fuzzy/thenmin.hpp>
#include <fuzzy/cogdefuzz.hpp>
#include <evolution/binaryshadowexpression.hpp>
#include <fuzzy/fuzzyFactory.hpp>
#include <fuzzy/aggplus.hpp>

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

    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float>           opAnd;
    fuzzy::OrMax<float>            opOr;
    fuzzy::ThenMin<float>          opThen;
    fuzzy::CogDefuzz<float>        opDefuzz;
    fuzzy::AggPlus<float> opAgg;

    //fuzzy expression factory
    fuzzy::FuzzyFactory<float> f(&opAnd, &opNot, &opAgg,&opOr, &opThen,  &opDefuzz);
    //membership func
    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);
    fuzzy::IsTriangle<float> cheap(0,5,10);
    fuzzy::IsTriangle<float> average(10,15,20);
    fuzzy::IsTriangle<float> generous(20,25,30);
    //values
    core::ValueModel<float> service(0);
    core::ValueModel<float> food(0);
    core::ValueModel<float> tips(0);
    core::Expression<float> *r =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&service,&poor),
                                    f.newIs(&tips,&cheap)
                            ),
                            f.newThen(
                                    f.newIs(&service,&good),
                                    f.newIs(&tips,&average)
                            )
                    ),
                    f.newThen(
                            f.newIs(&service,&excellent),
                            f.newIs(&tips,&generous)
                    )

            );
    core::Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);
    //apply input
    float serv;

    while (true)
    {
        std::cout << "service : ";
        std::cin >> serv;
        service.setValue(serv);


        std::cout << "tips -> " << system->evaluate() << std::endl;
    }
    return 0;

}