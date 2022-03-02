#include "MultiVote.h"
#include <utility>
#include "Voter.h"

MultiVote::MultiVote(std::shared_ptr<Voter> newVoter) : Vote{std::move(newVoter)}, choices{} { }

void MultiVote::makeChoice(unsigned int newChoice) {
    if(canMakeChoice(newChoice)) {
        choices.push_back(newChoice);
        voter->vote();
    }
}

bool MultiVote::canMakeChoice(unsigned int newChoice) {
    if(voter->canVote() || !choices.empty() && newChoice > 0) {
        for(unsigned int c: choices) {
            if (c == newChoice) return false; }
        return true;
    }
    else return false;
}

unsigned int MultiVote::getChoice(unsigned int choiceNo) {
    return choices[choiceNo];
}

unsigned int MultiVote::getChoiceNo() {
    return choices.size();
}
