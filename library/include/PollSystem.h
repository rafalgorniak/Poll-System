#ifndef PROJEKT_POLLSYSTEM_H
#define PROJEKT_POLLSYSTEM_H
#include <iostream>
#include <memory>
#include <vector>

class Poll;
class SingleChoicePoll;
class MultiChoicePoll;
class Display;
class DataStorage;
class PollSystem
{
public:
    void displayPoll(Poll &poll, std::shared_ptr<Display> display);
    void displayFromFile(std::shared_ptr<Display> display, std::shared_ptr<DataStorage> data, std::string path);
    void savePoll(Poll &poll, std::shared_ptr<DataStorage> data, std::string path);
    void makeSingleVote(SingleChoicePoll &poll, unsigned int optionNo);
    void makeMultiVote(MultiChoicePoll &poll, std::vector<unsigned int> optionsNo);
};

#endif //PROJEKT_POLLSYSTEM_H
