#include "PollSystem.h"
#include "Display.h"
#include "DataStorage.h"
#include "SingleChoicePoll.h"
#include "MultiChoicePoll.h"
#include "Voter.h"

void PollSystem::displayFromFile(std::shared_ptr<Display> display, std::shared_ptr<DataStorage> data, std::string path) {
    try{
        if(data->readValues(path).size() != data->readNames(path).size() || data->readNames(path).size() == 0) throw std::exception();
        display->display(data->readValues(path), data->readNames(path));
    }
    catch(std::exception&){
        std::cout << "Invalid number of names or values\n";
        throw;
    }
}

void PollSystem::displayPoll(Poll &poll, std::shared_ptr<Display> display) {
    try{
        if(poll.getOptionCounters().size() != poll.getOptionNames().size() || poll.getOptionNames().size() == 0) throw std::exception();
        display->display(poll.getOptionCounters(), poll.getOptionNames());
    }
    catch (std::exception&) {
        std::cout << "Invalid number of names or values\n";
        throw;
    }
}

void PollSystem::savePoll(Poll &poll, std::shared_ptr<DataStorage> data, std::string path) {

    try{
        if(poll.getOptionCounters().size() != poll.getOptionNames().size() || poll.getOptionNames().size() == 0) throw std::exception();
        data->SaveToFile(path, poll.getOptionCounters(), poll.getOptionNames());
    }
    catch (std::exception&) {
        std::cout << "Invalid number of names or values\n";
        throw;
    }
}

void PollSystem::makeSingleVote(SingleChoicePoll &poll, unsigned int optionNo) {
    auto v = std::make_shared<SingleVote>(std::make_shared<Voter>(poll.getVotesNumber()));
    v->makeChoice(optionNo);
    poll.addVote(v);
    poll.countVotes();
}

void PollSystem::makeMultiVote(MultiChoicePoll &poll, std::vector<unsigned int> optionsNo) {
    auto v = std::make_shared<MultiVote>(std::make_shared<Voter>(poll.getVotesNumber()));
    for (auto n: optionsNo) {
        v->makeChoice(n);
    }
    poll.addVote(v);
    poll.countVotes();
}
