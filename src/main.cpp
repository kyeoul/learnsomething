#include <pybind11/pybind11.h>
#include "primes.h"

namespace py = pybind11;

PYBIND11_MODULE(Primes, m) {
    py::class_<Primes>(m, "Primes")
        .def(py::init<>())
        .def("calcPrimes", &Primes::calcPrimes);
}

/*
<%
setup_pybind11(cfg)
%>
*/