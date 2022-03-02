#include <boost/test/unit_test.hpp>
#include "SingleChoicePoll.h"
#include "MultiChoicePoll.h"
#include "Voter.h"
#include "PollSystem.h"
#include "RelativePercentage.h"
#include "AbsolutePercentage.h"

BOOST_AUTO_TEST_SUITE(PollTests)

    BOOST_AUTO_TEST_CASE(ScalingTest) {
        std::shared_ptr<Option> o1 = std::make_shared<Option>("o1");
        std::shared_ptr<Option> o2 = std::make_shared<Option>("o2");
        std::shared_ptr<Option> o3 = std::make_shared<Option>("o3");
        SingleChoicePoll p = SingleChoicePoll("p", std::make_shared<RelativePercentage>());
        p.addOption(o1);
        p.addOption(o2);
        p.addOption(o3);

        std::shared_ptr<Voter> v1 = std::make_shared<Voter>(1);
        std::shared_ptr<Voter> v2 = std::make_shared<Voter>(2);
        std::shared_ptr<Voter> v3 = std::make_shared<Voter>(3);
        std::shared_ptr<Voter> v4 = std::make_shared<Voter>(4);
        std::shared_ptr<Voter> v5 = std::make_shared<Voter>(5);

        std::shared_ptr<SingleVote> sv1 = std::make_shared<SingleVote>(v1);
        std::shared_ptr<SingleVote> sv2 = std::make_shared<SingleVote>(v2);
        std::shared_ptr<SingleVote> sv3 = std::make_shared<SingleVote>(v3);
        std::shared_ptr<SingleVote> sv4 = std::make_shared<SingleVote>(v4);
        std::shared_ptr<SingleVote> sv5 = std::make_shared<SingleVote>(v5);

        sv1->makeChoice(1);
        sv2->makeChoice(1);
        sv3->makeChoice(2);
        sv4->makeChoice(3);
        sv5->makeChoice(0);

        p.addVote(sv1);
        p.addVote(sv2);
        p.addVote(sv3);
        p.addVote(sv4);
        p.addVote(sv5);

        p.countVotes();
        std::vector<float> v = p.getOptionCounters();

        BOOST_CHECK_EQUAL(v[0], 50.0);
        BOOST_CHECK_EQUAL(v[2], 25.0);

        p.changeStrategy(std::make_shared<AbsolutePercentage>());
        p.countVotes();
        v = p.getOptionCounters();
        BOOST_CHECK_EQUAL(v[0], 40.0);
        BOOST_CHECK_EQUAL(v[2], 20.0);
    }

BOOST_AUTO_TEST_SUITE_END()