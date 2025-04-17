#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() = default;
    virtual void show() {
        std::cout << "Base class method." << std::endl;
    }
};

class Derived1 : public Base {
public:
    void show() override {
        std::cout << "Derived1 class method." << std::endl;
    }
    void uniqueMethod() {
        std::cout << "Unique method of Derived1." << std::endl;
    }
};

class Derived2 : public Base {
public:
    void show() override {
        std::cout << "Derived2 class method." << std::endl;
    }
    void uniqueMethod() {
        std::cout << "Unique method of Derived2." << std::endl;
    }
};

// Function that returns a pointer to a derived class object
Base* createObject(int type) {
    if (type == 1) {
        return new Derived1();
    } else {
        return new Derived2();
    }
}

int main() {
    // Create a base-class pointer and assign a derived object to it
    Base* ptr = createObject(1); // Create Derived1 object

    // Use RTTI to check the actual type of the object
    if (typeid(*ptr) == typeid(Derived1)) {
        std::cout << "Object is of type Derived1." << std::endl;
    } else if (typeid(*ptr) == typeid(Derived2)) {
        std::cout << "Object is of type Derived2." << std::endl;
    }

    // Call the virtual function, which will invoke the correct method
    ptr->show();

    // If the object is of type Derived1, call a method that is unique to Derived1
    if (typeid(*ptr) == typeid(Derived1)) {
        // Downcast to Derived1 to call the unique method
        Derived1* derived1Ptr = dynamic_cast<Derived1*>(ptr);
        if (derived1Ptr) {
            derived1Ptr->uniqueMethod();
        }
    }

    // Clean up memory
    delete ptr;
    return 0;
}