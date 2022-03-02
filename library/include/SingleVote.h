#ifndef PROJEKT_SINGLEVOTE_H
#define PROJEKT_SINGLEVOTE_H
#include "Vote.h"

class SingleVote : public Vote {
protected:
    unsigned int choice;
public:
    explicit SingleVote(std::shared_ptr<Voter> voter);
    void makeChoice(unsigned int newChoice) override;
    unsigned int getChoice();
};

#endif //PROJEKT_SINGLEVOTE_H
