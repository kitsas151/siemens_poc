#if 0

struct Base {
    virtual void foo();
};

struct A : Base {
    void foo() final; {}// Base::foo is overridden, and A::foo is final
    // Error: bar cannot be final as it is non-virtual
    void bar() final; {}
};

struct B final : A {
    // Error: foo cannot be overridden as it is final in A
    void foo() override; {}
};

// Error: B is final
struct C : B {};

int main() {
    // Compile-time errors will occur due to the use of final
    return 0;
}


#endif