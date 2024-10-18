#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(){
    int random_number = rand() % 3;
    std::cout << "Random number [0: A , 1: B, 2: C] : " << random_number << std::endl;
    switch (random_number){
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            std::cout << "Invalid Random Number" << std::endl;
            return nullptr;
    }
}

void identify(Base *p){
    if (dynamic_cast<A *>(p)) {
        std::cout << "Pointer is pointing to an object of class A" << std::endl;
    }
    else if (dynamic_cast<B *>(p)) {
        std::cout << "Pointer is pointing to an object of class B" << std::endl;
    }
    else if (dynamic_cast<C *>(p)) {
        std::cout << "Pointer is pointing to an object of class C" << std::endl;
    } else {
        std::cout << "Pointer is pointing to an unknown object" << std::endl;
    }
}

void identify(Base &p){
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch( const std::exception& e ) {}
}
