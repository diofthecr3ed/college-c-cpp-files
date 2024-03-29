#include <iostream>

class Base {
public:
    virtual void func() {
        std::cout << "Base::func()" << std::endl;
    }

    virtual void func(int x) {
        std::cout << "Base::func(int)" << std::endl;
    }

    virtual void func(double y) {
        std::cout << "Base::func(double)" << std::endl;
    }
};

class Derived : public Base {
public:
    void func() override {
        std::cout << "Derived::func()" << std::endl;
    }
};

int main() {
    Derived derivedObj;

    // Call overridden function through derived-class object
    derivedObj.func();  // Outputs: Derived::func()

    // Upcast the address of the object to the base
    Base* basePtr = &derivedObj;

    // Call all three functions through the base pointer
    basePtr->func();    // Outputs: Derived::func() (dynamic dispatch)
    basePtr->func(10);  // Outputs: Base::func(int)
    basePtr->func(3.14); // Outputs: Base::func(double)

    return 0;
}

