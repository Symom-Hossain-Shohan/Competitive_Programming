#include <iostream>

class Singleton {
private:
    // Private constructor
    Singleton() {
        std::cout << "Singleton instance created\n";
    }

public:
    // Deleted copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static method to get the singleton instance
    static Singleton& getInstance() {
        // Static local variable: initialized only once, thread-safe in C++11+
        static Singleton instance;
        return instance;
    }

    // Example method
    void doSomething() {
        std::cout << "Doing something with Singleton\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    std::cout << "s1 address: " << &s1 << "\n";
    std::cout << "s2 address: " << &s2 << "\n";

    s1.doSomething();

    return 0;
}