#ifndef PROJEKT_VOTE_H
#define PROJEKT_VOTE_H
#include <iostream>
#include <memory>

class Voter;

class Vote {
protected:
    std::shared_ptr<Voter> voter;
public:
    explicit Vote(std::shared_ptr<Voter> newVoter);
    virtual void makeChoice(unsigned int newChoice) = 0;
};

#endif //PROJEKT_VOTE_H
