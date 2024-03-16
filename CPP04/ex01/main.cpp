#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(){

    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();

    std::cout << std::endl;
    delete j;

    std::cout << std::endl;
    delete i;
    std::cout << std::endl;

    Brain alp;
    Brain berna(alp);

    std::cout << std::endl;

    std::cout << alp.getIdeas() << std::endl;
    std::cout << berna.getIdeas() << std::endl;

    std::cout << std::endl;

    alp = berna;

    alp.setIdeas(0,"Berna");
    berna.setIdeas(0, "Alp");

    std::cout << std::endl;

    std::cout << alp.getIdeas(0) << std::endl;
    std::cout << berna.getIdeas(0) << std::endl;

    std::cout << std::endl;
    
    return 0;
}