#include <MultiChoicePoll.h>

MultiChoicePoll::MultiChoicePoll(std::string name, std::shared_ptr<PercentageStrategy> strategy) : Poll(std::move(name), strategy) { }

void MultiChoicePoll::addVote(std::shared_ptr<MultiVote> vote) {
    votes.push_back(vote);
}

void MultiChoicePoll::countVotes() {
    resetIncorrectVotes();
    for(std::shared_ptr<Option> option : options) {
        option->resetCounter();
    }
    for(std::shared_ptr<Vote> _vote_ : votes) {
        std::shared_ptr<MultiVote> vote = std::dynamic_pointer_cast<MultiVote>(_vote_);
        if(vote->getChoiceNo() == 0) incorrectVotes++;
        for (unsigned int c = 0; c < vote->getChoiceNo(); c++) {
            if(vote->getChoice(c) == 0 || vote->getChoice(c) > getOptionsNumber()) incorrectVotes++;
            else options[vote->getChoice(c) - 1]->increaseCounter();
        }
    }
}
