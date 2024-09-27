#include "Base.hpp"

int main(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	Base *alp = generate();
	identify(alp);
	Base *berna = generate();
	Base &alp2 = *berna;
	identify(alp2);
	return 0;
}