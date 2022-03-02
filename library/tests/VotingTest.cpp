#include <memory>
#include <boost/test/unit_test.hpp>
#include "Voter.h"
#include "SingleVote.h"
#include "MultiVote.h"

BOOST_AUTO_TEST_SUITE(VotingTests)

    BOOST_AUTO_TEST_CASE(VoterTest) {
        Voter V1 = Voter(1);
        BOOST_CHECK_EQUAL(V1.getVoterID(), 1);
        BOOST_CHECK_EQUAL(V1.canVote(), true);
        V1.vote();
        BOOST_CHECK_EQUAL(V1.canVote(), false);
    }

    BOOST_AUTO_TEST_CASE(SingleVoteTest) {
        std::shared_ptr<Voter> v1 = std::make_shared<Voter>(1);
        SingleVote sv1 = SingleVote(v1);;
        BOOST_CHECK_EQUAL(sv1.getVoter()->canVote(), true);
        BOOST_CHECK_EQUAL(sv1.getChoice(), 0);
        sv1.makeChoice(1);
        BOOST_CHECK_EQUAL(sv1.getVoter()->canVote(), false);
        BOOST_CHECK_EQUAL(sv1.getChoice(), 1);
        sv1.makeChoice(2);
        BOOST_CHECK_EQUAL(sv1.getChoice(), 1);
        SingleVote sv2 = SingleVote(v1);
        sv2.makeChoice(1);
        BOOST_CHECK_EQUAL(sv2.getChoice(), 0);
    }

    BOOST_AUTO_TEST_CASE(MultiVoteTest) {
        std::shared_ptr<Voter> v1 = std::make_shared<Voter>(1);
        MultiVote mv1 = MultiVote(v1);
        BOOST_CHECK_EQUAL(mv1.getVoter()->canVote(), true);
        BOOST_CHECK_EQUAL(mv1.getChoiceNo(), 0);
        mv1.makeChoice(1);
        BOOST_CHECK_EQUAL(mv1.getVoter()->canVote(), false);
        BOOST_CHECK_EQUAL(mv1.getChoice(0), 1);
        mv1.makeChoice(2);
        BOOST_CHECK_EQUAL(mv1.getChoice(1), 2);
        mv1.makeChoice(2);
        BOOST_CHECK_EQUAL(mv1.getChoiceNo(), 2);
        MultiVote mv2 = MultiVote(v1);
        mv2.makeChoice(1);
        BOOST_CHECK_EQUAL(mv2.getChoiceNo(), 0);
    }

BOOST_AUTO_TEST_SUITE_END()