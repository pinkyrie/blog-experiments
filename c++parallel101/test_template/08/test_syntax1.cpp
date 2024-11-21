//
// Created by Matoka on 2024/11/8.
//
#include <iostream>
using namespace std;

template<class T> void f(T x, T y) {
    cout << "Template: " << typeid(x).name() << ", " << typeid(y).name() << endl;
}

void f(int w, int z) {
    cout << "Non-template: " << typeid(w).name() << ", " << typeid(z).name() << endl;
}

int main() {
    f( 1 ,  2 );
    f('a', 'b');
    f( 1 , 'b');
}


