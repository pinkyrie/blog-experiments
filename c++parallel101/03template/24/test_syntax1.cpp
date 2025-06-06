#include<iostream>
using namespace std;
template<typename T>
T max (T& a, T& b){
    return a > b ? a : b;
}

template<typename T>
void foo(T& x, T& y)
{
    cout << x << endl;
    cout << y << endl;
}

int main() {
    int i = 10;
    int const c = 42;
    /*::max(i, c); // error*/
    ::max(c, c); // OK: T is deduced as int
    int& ir = i;
    ::max(i, ir); // OK: T is deduced as int
    int arr[4];
    /*foo(&i, arr); // error*/
}