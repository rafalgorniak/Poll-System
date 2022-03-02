#include <utility>
#include "SingleVote.h"
#include "Voter.h"

SingleVote::SingleVote(std::shared_ptr<Voter> newVoter) : Vote{std::move(newVoter)}, choice{0} { }

void SingleVote::makeChoice(unsigned int newChoice) {
    if(voter->canVote()){
        choice = newChoice;
        voter->vote();
    }
}

unsigned int SingleVote::getChoice() {
    return choice;
}


