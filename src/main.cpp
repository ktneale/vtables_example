/*
 * Written by Kevin Neale (C) 2015.
 *
 * Example of Dynamic Binding/Run Time polymorphism in C++
 *
 */
#include <iostream>

using namespace std;

//Example of a class heirarchy with virtual functions.
//The compiler will create vtables for each class to facilitate dynamic binding.

class Mammal
{
    public:
        Mammal() : m_age(0), m_weight(0){};
        virtual ~Mammal(){};        //Virtual destructor
        virtual void Speak(){cout << "Mammal speak!\n";};

    protected:
        int m_age;
        int m_weight;
};

class Cat : public Mammal
{
    public:
        void Speak(){cout << "Meow!\n";};
        void Climb(){cout << "Climb!\n";};
};

class Dog : public Mammal
{
    public:
        void Speak(){cout << "Woof!\n";};
        void WagTail(){cout << "Tail wag!\n";};
};


int main()
{
    Mammal * mammal = NULL;

    int in=0;

    while(1)
    {
        cout << "Enter, 1 - Mammal, 2 - Cat, 3 - Dog\n";

        cin >> in;

        switch(in)
        {
            case 1: 
            {
                mammal = new Mammal();
                break;
            }
            case 2: 
            {
                mammal = new Cat();
                break;
            }
            case 3: 
            {
                mammal = new Dog();
                break;
            }
            default: 
            {
                break;
            }
        }

        mammal->Speak();
    }

    return 0;

}
