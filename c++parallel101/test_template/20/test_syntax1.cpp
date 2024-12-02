#include <iostream>
#include <utility>
using namespace std;

// Function that demonstrates lvalue reference handling
template<typename T>
void func1(T& a) {

    // Inform that func1 is called with lvalue reference (T&)
    cout << "func1 called with lvalue reference (T&)" << endl;

    // T& remains as T&
    T& ref = a;

    // Display the value of ref
    cout << "Value of ref: " << ref << endl;
}

// Function that demonstrates rvalue reference handling and collapsing when passed an lvalue
template<typename T>
void func2(T&& a) {

    // Inform that func2 is called with rvalue reference (T&&)
    cout << "func2 called with rvalue reference (T&&)" << endl;

    // T&& remains T&& or collapses to T& if T is lvalue reference
    T&& ref = forward<T>(a);

    // Display the value of ref
    cout << "Value of ref: " << ref << endl;
}

int main() {

    // Initialize an integer variable x with value 10
    int x = 10;

    // Call func1 with lvalue (x)
    cout << "Calling func1 with lvalue (x):" << endl;
    func1(x);  // T deduced as int, ref becomes int&

    // Call func2 with lvalue (x)
    cout << "\nCalling func2 with lvalue (x):" << endl;
    func2(x);  // T deduced as int&, ref becomes int& due to reference collapsing

    // Call func2 with rvalue (std::move(x))
    cout << "\nCalling func2 with rvalue (move(x)):" << endl;
    func2(move(x));  // T deduced as int, ref becomes int&&

    return 0;
}