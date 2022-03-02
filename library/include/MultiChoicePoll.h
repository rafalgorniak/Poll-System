#ifndef PROJEKT_MULTICHOICEPOLL_H
#define PROJEKT_MULTICHOICEPOLL_H
#include "Poll.h"

class MultiChoicePoll: public Poll
{
public:
    explicit MultiChoicePoll(std::string name, std::shared_ptr<PercentageStrategy> strategy);
    void addVote(std::shared_ptr<MultiVote> vote);
    void countVotes() override;
};


#endif //PROJEKT_MULTICHOICEPOLL_H
