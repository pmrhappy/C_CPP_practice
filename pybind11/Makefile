all:
	c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` main.cpp -o test_module.so`python3-config --extension-suffix` #-I<dir_path/with/pybind11.h> -I<dir_path/with/Python.h>
