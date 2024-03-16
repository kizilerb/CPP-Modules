#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>
#include <string>

class Brain{
    private:
        std::string ideas[100];
     public:
        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);
        ~Brain();

        const std::string* getIdeas() const;
        std::string getIdeas(int index) const;
        void setIdeas(int index, const std::string& line);
};
#endif