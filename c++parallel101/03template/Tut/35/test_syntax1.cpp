#include <iostream>

void testByAddress(const char* str) {
    std::cout << "Address in function: " << &str << std::endl;
}

void testByReference(const char*& ref) {
    std::cout << "Address in function (by reference): " << &ref << std::endl;
}

int main() {
    const char* original = "Hello, world!";
    const char*& ref = original;


    std::cout << "Address of original: " << &original << std::endl;
    std::cout << "Address of ref: " << &ref << std::endl;

    testByAddress(original);
    testByReference(original);


    testByAddress(ref);
    testByReference(ref);

    return 0;
}
