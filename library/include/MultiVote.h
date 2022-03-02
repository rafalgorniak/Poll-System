#ifndef PROJEKT_MULTIVOTE_H
#define PROJEKT_MULTIVOTE_H
#include <vector>
#include "Vote.h"

class MultiVote : public Vote {
protected:
    std::vector<unsigned int> choices;
public:
    explicit MultiVote(std::shared_ptr<Voter> voter);
    void makeChoice(unsigned int newChoice) override;
    bool canMakeChoice(unsigned int newChoice);
    unsigned int getChoice(unsigned int choiceNo);
    unsigned int getChoiceNo();
};

#endif //PROJEKT_MULTIVOTE_H
