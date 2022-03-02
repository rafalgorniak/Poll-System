#ifndef PROJEKT_RELATIVEPERCENTAGE_H
#define PROJEKT_RELATIVEPERCENTAGE_H
#include "PercentageStrategy.h"

class RelativePercentage : public PercentageStrategy {
public:
    float scale(unsigned int votes, unsigned int correctVotes, unsigned int incorrectVotes);
};

#endif //PROJEKT_RELATIVEPERCENTAGE_H
