#include <iostream>


using namespace std;


// application
int main() {
    int i, j;
    int *p = &j;

    // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
    i = 7;
    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;
     p = &i;
    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;
    // Incorrect usage: the constant ci is a non-modifiable lvalue (C3892).
    const int ci = 7;
}
