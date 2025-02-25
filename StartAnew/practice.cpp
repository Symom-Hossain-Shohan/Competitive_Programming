#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal is speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog is barking" << endl;
    }
};

class Shared
{
    static int a;
    int b;

public:
    Shared(int i, int j)
    {
        a = i, b = j;
    }

    void print()
    {
        cout << a << " " << b << endl;
    }
};

int Shared::a;

/**
 * The main entry point of the program.
 * It creates an Animal object, calls its speak() method, then creates a Dog object and calls its speak() method.
 */

int main()
{
    // Animal *animal = new Animal();
    // animal->speak();

    // animal = new Dog();
    // animal->speak();

    Shared X(1, 1);
    X.print();
    Shared Y(2, 2);
    Y.print();
    X.print();
}