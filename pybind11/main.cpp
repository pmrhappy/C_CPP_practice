#include <pybind11/pybind11.h>

int minus(int a, int b){
    return a - b;
}

PYBIND11_MODULE(test_module, m) {
    m.doc() = "xxxxxxxxxxx";
    m.def("minus", &minus, "function for a-b");
}
