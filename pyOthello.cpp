#include<pybind11/pybind11.h>
#include<pybind11/numpy.h>
//#include<algorithm>
//#include<numeric>
//#include <iostream>
#include "othello.h"

namespace py = pybind11;

//auto nptest() {
//				char *a[100] = { 0 };
//				auto result = py::array_t<char>(100);
//				char* ptr=(char*)result.request().ptr;
//				int x = 11;
//				py::list d;
//				
//				d.append(x);
//				d.append(result);
//
//				//char *ptr = (char *)z.ptr;
//				//z.ptr = a;
//				////memcpy(ptr, a, i);
//				for (char i = 0; i < 100; ++i) {
//								ptr[i] = 100-i;
//				}
//
//				return d;
//}

PYBIND11_PLUGIN(pyOthello) {
				py::module m("pyOthelo", "pybind11 example plugin");
				//m.def("nptest", &nptest, "A function which adds scalar to ndarray");
				//py::module m("example", "pybind11 example plugin");

				py::class_<othello>(m, "othello")
								.def(py::init<>())
								.def("show",&othello::show)
								.def("select", &othello::select);;
				return m.ptr();
}