#include <iostream>

// 前向声明模板类 Bar
template <typename T>
class Bar;

template <typename T>
class Foo {
private:
    Bar<T>* bar; // Foo 使用了 Bar
public:
    Foo() : bar(nullptr) {}
    void setBar(Bar<T>* b) { bar = b; }
    void print() { std::cout << "This is Foo" << std::endl; }
    void printBar() { bar->print(); }
};

template <typename T>
class Bar {
private:
    Foo<T>* foo; // Bar 使用了 Foo
public:
    Bar() : foo(nullptr) {}
    void setFoo(Foo<T>* f) { foo = f; }
    void print() { std::cout << "This is Bar" << std::endl; }
    void printFoo() { foo->print(); }
};

int main() {
    Foo<int> fooObj;
    Bar<int> barObj;

    fooObj.setBar(&barObj);
    barObj.setFoo(&fooObj);

    fooObj.print();
    barObj.print();

    fooObj.setBar(&barObj);
    barObj.setFoo(&fooObj);

    fooObj.printBar();
    barObj.printFoo();

    return 0;
}
