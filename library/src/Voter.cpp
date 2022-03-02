#include <Voter.h>

Voter::Voter(unsigned int ID): voterID(ID), voted(false) { }

unsigned int Voter::getVoterID() {
    return voterID;
}

void Voter::vote() {
    voted = true;
}

bool Voter::canVote() {
    return (voted + 1) % 2;
}

