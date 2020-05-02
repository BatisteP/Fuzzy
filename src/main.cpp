#include <iostream>
#include <core/valuemodel.hpp>
#include <core/binaryexpressionmodel.hpp>
#include <core/unaryexpressionmodel.hpp>
#include <fuzzy/andmin.hpp>
#include <fuzzy/andmult.hpp>
#include <fuzzy/istriangle.hpp>
#include <fuzzy/notminus1.hpp>
#include <fuzzy/notminus.hpp>
#include <fuzzy/ormax.hpp>
#include <fuzzy/thenmult.hpp>
#include <fuzzy/orplus.hpp>
#include <fuzzy/thenmin.hpp>
#include <fuzzy/cogdefuzz.hpp>
//#include <fuzzy/fuzzyFactoryBis.hpp>
#include <fuzzy/fuzzyFactory.hpp>
#include <fuzzy/aggplus.hpp>
#include <fuzzy/aggmax.hpp>
#define ASSERT_ON
#include "utils.h"
void testingOperators(){
    core::ValueModel<float> v1(0);
    core::ValueModel<float> v0_7(0.7);
    core::ValueModel<float> v2(5);
    core::ValueModel<float> v3(10);
    core::ValueModel<float> v4(15);
    //test isTriangle
    fuzzy::IsTriangle<float> isTriangle(0, 10, 30);
    core::ValueModel<float> triangleEval1 = isTriangle.evaluate(&v1);
    core::ValueModel<float> triangleEval2 = isTriangle.evaluate(&v2);
    core::ValueModel<float> triangleEval3 = isTriangle.evaluate(&v3);
    core::ValueModel<float> triangleEval4 = isTriangle.evaluate(&v4);

    ASSERT(triangleEval1.evaluate() == 0);
    ASSERT(triangleEval2.evaluate() == 0.5);
    ASSERT(triangleEval3.evaluate() == 1);

    //test autres opérateurs
    fuzzy::AggMax<float> aggMax;
    fuzzy::AggPlus<float> aggPlus;
    fuzzy::AndMin<float> andMin;
    fuzzy::AndMult<float> andMult;
    fuzzy::NotMinus<float> notMinus;
    fuzzy::NotMinus1<float> notMinus1;
    fuzzy::OrMax<float> orMax;
    fuzzy::OrPlus<float> orPlus;
    fuzzy::ThenMin<float> thenMin;
    fuzzy::ThenMult<float> thenMult;
    //v1 = 0, v2= 5, v3 = 10, v0_7 = 0.7
    ASSERT(aggMax.evaluate(&v2,&v3) == 10);
    ASSERT(orMax.evaluate(&v2,&v3) == 10);
    ASSERT(aggPlus.evaluate(&v2,&v3) == 15);
    ASSERT(orPlus.evaluate(&v1,&v0_7) == 0.7f);
    ASSERT(orPlus.evaluate(&v0_7,&v0_7) == 1);
    ASSERT(andMult.evaluate(&v2,&v3) == 50);
    ASSERT(thenMult.evaluate(&v2,&v3) == 50);
    ASSERT(thenMin.evaluate(&v2,&v3) == 5);
    ASSERT(notMinus.evaluate(&v2) == -5);
    ASSERT(notMinus1.evaluate(&v2) == -4);

    //test unary
    core::UnaryExpressionModel<float> unary(&v4, &isTriangle);
    ASSERT((triangleEval4.evaluate() == unary.evaluate() )&& unary.evaluate() == 0.75);

    //test binary
    core::BinaryExpressionModel<float> binary( &v2, &v3,&thenMult);
    ASSERT(binary.evaluate() == 50);
}

void testingFactoryMamdani (){
    fuzzy::NotMinus<float>         opNot;
    fuzzy::AndMin<float>           opAnd;
    fuzzy::OrMax<float>            opOr;
    fuzzy::ThenMult<float>          opThen;
    fuzzy::AggPlus<float>          opAgg;
    fuzzy::CogDefuzz<float>        opDefuzz;

    //fuzzy factory
    fuzzy::FuzzyFactory<float> f(&opAnd,&opNot,&opAgg,&opOr,&opThen,&opDefuzz);

    //functions
    //service
    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);
    //food
    fuzzy::IsTriangle<float> rancid(-5,0,5);
    fuzzy::IsTriangle<float> delicious(5,10,15);
    //tips
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
                                    f.newOr(
                                            f.newIs(&service,&poor),
                                            f.newIs(&food,&rancid )
                                    ),
                                    f.newIs(&tips, &cheap)
                            ),
                            f.newThen(
                                    f.newIs( &service,&good),
                                    f.newIs(&tips,&average)
                            )
                    ),
                    f.newThen(
                            f.newOr(
                                    f.newIs(&service,&excellent),
                                    f.newIs(&food,&delicious)
                            ),
                            f.newIs(&tips,&generous )
                    )
            );
    //defuzzification
    core::Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

    //apply input
    float serviceF, foodF;

    while (true)
    {
        std::cout << "service : ";
        std::cin >> serviceF;
        service.setValue(serviceF);
        std::cout << "food : ";
        std::cin >> foodF;
        food.setValue(foodF);
        std::cout << "tips -> " << system->evaluate() << std::endl;
    }


}
void testSugenoDefuzz(){
    fuzzy::NotMinus<float>         opNot;
    fuzzy::AndMin<float>           opAnd;
    fuzzy::OrMax<float>            opOr;
    fuzzy::SugenoThen<float>          opThen;
    fuzzy::AggPlus<float>          opAgg;
    fuzzy::SugenoDefuzz<float> opSugDefuzz;

    std::vector<float> coef;
    coef.push_back(1);
    coef.push_back(1);
    coef.push_back(1);
    fuzzy::SugenoConclusion<float> opConclusion(&coef);
    fuzzy::CogDefuzz<float>        opDefuzz;

    //fuzzy factory

    fuzzy::FuzzyFactory<float> f(&opAnd,&opNot,&opAgg,&opOr,&opThen,&opSugDefuzz, &opConclusion);


    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);

    fuzzy::IsTriangle<float> rancid(-5,0,5);
    fuzzy::IsTriangle<float> delicious(5,10,15);

    core::ValueModel<float> service(0);
    core::ValueModel<float> food(0);

    std::vector<const core::Expression<float>*> SC_service_food;
    SC_service_food.push_back(&service);
    SC_service_food.push_back(&food);

    std::vector<const core::Expression<float>*> SC_service;
    SC_service.push_back(&service);


    std::vector<const core::Expression<float>*> rules;

    rules.push_back(
            f.newThen(
                    f.newOr(
                            f.newIs(&service,&poor ),
                            f.newIs(&food,&rancid )
                    ),
                    f.newSConclusion(&SC_service_food)
            ));

    rules.push_back(
            f.newThen(
                    f.newIs(&service,&good ),
                    f.newSConclusion(&SC_service)
            ));

    rules.push_back(
            f.newThen(
                    f.newOr(
                            f.newIs( &service,&excellent),
                            f.newIs(&food,&delicious )
                    ),
                    f.newSConclusion(&SC_service_food)
            ));
    //defuzzification
    core::Expression<float> *system = f.newSugeno(&rules);

    //apply input
    float s, foo;
    while (true)
    {
        std::cout << "service : ";
        std::cin >> s;
        service.setValue(s);
        std::cout << "food : ";
        std::cin >> foo;
        food.setValue(foo);
        std::cout << "tips -> " << system->evaluate() << std::endl;
    }
}


void testMamdaniProf(){
    fuzzy::NotMinus<float>         opNot;
    fuzzy::AndMin<float>           opAnd;
    fuzzy::OrMax<float>            opOr;
    fuzzy::SugenoThen<float>          opThen;
    fuzzy::AggPlus<float>          opAgg;
    fuzzy::CogDefuzz<float> opCogDefuzz;

    //fuzzy factory
    fuzzy::FuzzyFactory<float> f(&opAnd,&opNot, &opAgg,&opOr,&opThen,&opCogDefuzz);

    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);

    fuzzy::IsTriangle<float> cheap(0,5,10);
    fuzzy::IsTriangle<float> average(10,15,20);
    fuzzy::IsTriangle<float> generous(20,25,30);

    core::ValueModel<float> service(0);
    core::ValueModel<float> food(0);
    core::ValueModel<float> tips(0);
    core::Expression<float> *r =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&service, &poor),
                                    f.newIs(&tips, &cheap)
                            ),
                            f.newThen(
                                    f.newIs( &service,&good),
                                    f.newIs(&tips,&average)
                            )
                    ),
                    f.newThen(
                                    f.newIs(&service,&excellent),
                                    f.newIs(&tips,&generous)
                    )
            );
    //defuzzification
    core::Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

    //apply input
    float serviceF, foodF;

    while (true)
    {
        std::cout << "service : ";
        std::cin >> serviceF;
        service.setValue(serviceF);
        std::cout << "food : ";
        std::cin >> foodF;
        food.setValue(foodF);
        std::cout << "tips -> " << system->evaluate() << std::endl;
    }


}

int main() {
    //testingOperators();
    std::cout << "unitary testing of the operators done" << std::endl;
    //testSugenoDefuzz();
    //testingFactoryMamdani();
    testMamdaniProf();

    /*
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
    core::Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 0.5);
    //apply input
    float serv;

    while (true)
    {
        std::cout << "service : ";
        std::cin >> serv;
        service.setValue(serv);


        std::cout << "tips -> " << system->evaluate() << std::endl;
    }
    return 0;*/

}