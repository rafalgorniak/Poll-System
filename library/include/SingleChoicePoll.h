#ifndef PROJEKT_SINGLECHOICEPOLL_H
#define PROJEKT_SINGLECHOICEPOLL_H
#include "Poll.h"

class SingleChoicePoll: public Poll
{
public:
    explicit SingleChoicePoll(std::string name, std::shared_ptr<PercentageStrategy> strategy);
    void addVote(std::shared_ptr<SingleVote> vote);
    void countVotes() override;
};


#endif //PROJEKT_SINGLECHOICEPOLL_H
