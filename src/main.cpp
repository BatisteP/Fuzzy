#include <iostream>
#include <core/valuemodel.hpp>

int main() {
    core::ValueModel<int> v;
    v.setValue(33);
    std::cout << v.evaluate() << std::endl;
}