#ifndef PROJEKT_HEADER_H
#define PROJEKT_HEADER_H

class Voter {
private:
    unsigned int voterID;
    bool voted;
public:
    explicit Voter(unsigned int ID);
    unsigned int getVoterID();
    void vote();
    bool canVote();
};

#endif //PROJEKT_HEADER_H
