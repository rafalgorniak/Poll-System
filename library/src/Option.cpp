#include <Option.h>
#include <utility>
#include <memory>

Option::Option(std::string name): optionName{name}, votesCounter{0} { }

std::string Option::getName() {
    return this->optionName;
}

unsigned int Option::getCounter() {
    return this->votesCounter;
}

void Option::increaseCounter() {
    votesCounter++;
}

void Option::resetCounter() {
    votesCounter = 0;
}

