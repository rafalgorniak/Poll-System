#include <utility>
#include "Vote.h"

Vote::Vote(std::shared_ptr<Voter> newVoter) : voter{std::move(newVoter)} { }
