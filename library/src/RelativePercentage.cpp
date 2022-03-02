#include "RelativePercentage.h"

float RelativePercentage::scale(unsigned int votes, unsigned int correctVotes, unsigned int incorrectVotes) {
    return (100.0 * votes) / correctVotes;
}
