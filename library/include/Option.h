#ifndef PROJEKT_OPTION_H
#define PROJEKT_OPTION_H
#include <string>

class Option
{
    std::string optionName;
    unsigned int votesCounter;
public:
    explicit Option(std::string name);
    std::string getName();
    unsigned int getCounter();
    void increaseCounter();
    void resetCounter();
};

#endif //PROJEKT_OPTION_H
