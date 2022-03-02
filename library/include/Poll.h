#ifndef PROJEKT_POLL_H
#define PROJEKT_POLL_H
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include "SingleVote.h"
#include "MultiVote.h"
#include "Option.h"

class PercentageStrategy;

class Poll
{
protected:
    std::string pollName;
    std::vector<std::shared_ptr<Vote>> votes;
    unsigned int incorrectVotes;
    std::vector<std::shared_ptr<Option>> options;
    std::shared_ptr<PercentageStrategy> percentageStrategy;
public:
    explicit Poll(std::string name, std::shared_ptr<PercentageStrategy> strategy);
    void addOption(std::shared_ptr<Option>);
    void removeLastOption();
    virtual void countVotes() = 0;
    std::string getPollName();
    unsigned int getVotesNumber();
    unsigned int getOptionsNumber();
    unsigned int getOptionCounter(std::shared_ptr<Option> option);
    std::vector<float> getOptionCounters();
    std::vector<std::string> getOptionNames();
    unsigned int getIncorrectVotes();
    void resetIncorrectVotes();
    void changeStrategy(std::shared_ptr<PercentageStrategy> strategy);
};







#endif //PROJEKT_POLL_H
