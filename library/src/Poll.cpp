#include <Poll.h>
#include <utility>
#include "Vote.h"
#include "AbsolutePercentage.h"
#include "RelativePercentage.h"

Poll::Poll(std::string name, std::shared_ptr<PercentageStrategy> strategy): pollName{std::move(name)}, votes{}, incorrectVotes{0}, options{}, percentageStrategy{strategy} { }

void Poll::addOption(std::shared_ptr<Option> option) {
    options.push_back(option);
}

void Poll::removeLastOption() {
    if(getOptionsNumber() != 0) options.pop_back();
}

std::string Poll::getPollName() {
    return pollName;
}

unsigned int Poll::getVotesNumber() {
    return votes.size();
}

unsigned int Poll::getOptionsNumber() {
    return options.size();
}

unsigned int Poll::getIncorrectVotes() {
    return incorrectVotes;
}

void Poll::resetIncorrectVotes() {
    incorrectVotes = 0;
}

unsigned int Poll::getOptionCounter(std::shared_ptr<Option> option) {
    return option->getCounter();
}

std::vector<float> Poll::getOptionCounters() {
    std::vector<float> counters;
    unsigned int sum = 0;
    for(auto option : options){
        sum += option->getCounter();
    }
    try {
        if (sum == 0) throw std::exception();
        for (auto option: options) {
            counters.push_back(percentageStrategy->scale(getOptionCounter(option), sum, incorrectVotes));
        }
    }
    catch (std::exception&){
        std::cout << "There are no correct votes\n";
        throw;
    }
    return counters;
}

std::vector<std::string> Poll::getOptionNames() {
    std::vector<std::string> names;
    for(auto option : options){
        names.push_back(option->getName());
    }
    return names;
}

void Poll::changeStrategy(std::shared_ptr<PercentageStrategy> strategy) {
    percentageStrategy = strategy;
}

