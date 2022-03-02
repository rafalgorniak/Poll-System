#include "AbsolutePercentage.h"

float AbsolutePercentage::scale(unsigned int votes, unsigned int correctVotes, unsigned int incorrectVotes) {
    return (100.0 * votes) / (correctVotes + incorrectVotes);
}
