#include <pybind11/pybind11.h>

struct Pet
{
    std::string name = "ty";
    std::string intro = "love the world";
};

std::unique_ptr<Pet> ReturnPointer() {
    return std::unique_ptr<Pet>(new Pet());
}

PYBIND11_MODULE(test, m) {
    m.doc() = "pybind11 example plugin"; 
    m.def("ReturnPointer", &ReturnPointer);
}

