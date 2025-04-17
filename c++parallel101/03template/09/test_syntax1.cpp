//
// Created by Matoka on 2024/11/8.
//
#include <iostream>
using namespace std;

template<class T>
void f_tmpl () {
    typename T::foo * x;
}

struct X {
    typedef int foo;
};
struct Y {
    static  int const foo = 123;
};