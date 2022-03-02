#ifndef PROJEKT_ABSOLUTEPERCENTAGE_H
#define PROJEKT_ABSOLUTEPERCENTAGE_H
#include "PercentageStrategy.h"

class AbsolutePercentage : public PercentageStrategy {
public:
    float scale(unsigned int votes, unsigned int correctVotes, unsigned int incorrectVotes);
};

#endif //PROJEKT_ABSOLUTEPERCENTAGE_H
