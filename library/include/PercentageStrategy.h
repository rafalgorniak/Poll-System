#ifndef PROJEKT_PERCENTAGESTRATEGY_H
#define PROJEKT_PERCENTAGESTRATEGY_H

class PercentageStrategy {
public:
    virtual ~PercentageStrategy() = default;
    virtual float scale(unsigned int votes, unsigned int correctVotes, unsigned int incorrectVotes) = 0;
};

#endif //PROJEKT_PERCENTAGESTRATEGY_H
