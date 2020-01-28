#include <iostream>
#include <core/valuemodel.hpp>

int main() {
    core::ValueModel<std::string> v;
    v.setValue("Hello world !");
    std::cout << v.evaluate() << std::endl;
}