#include <SingleChoicePoll.h>

SingleChoicePoll::SingleChoicePoll(std::string name, std::shared_ptr<PercentageStrategy> strategy): Poll(std::move(name), strategy) { }

void SingleChoicePoll::addVote(std::shared_ptr<SingleVote> vote) {
    votes.push_back(vote);
}

void SingleChoicePoll::countVotes() {
    resetIncorrectVotes();
    for(std::shared_ptr<Option> option : options){
        option->resetCounter();
    }
    for(std::shared_ptr<Vote> _vote_ : votes){
        std::shared_ptr<SingleVote> vote = std::dynamic_pointer_cast<SingleVote>(_vote_);
        if(vote->getChoice() == 0 || vote->getChoice() > getOptionsNumber()) incorrectVotes++;
        else options[vote->getChoice() - 1]->increaseCounter();
    }
}
