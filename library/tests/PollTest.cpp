#include <boost/test/unit_test.hpp>
#include "SingleChoicePoll.h"
#include "MultiChoicePoll.h"
#include "Option.h"
#include "Voter.h"
#include "SingleVote.h"
#include "MultiVote.h"
#include "RelativePercentage.h"
#include "AbsolutePercentage.h"

BOOST_AUTO_TEST_SUITE(PollTests)

    BOOST_AUTO_TEST_CASE(OptionTest) {
        std::shared_ptr<Option> o1 = std::make_shared<Option>("o1");
        std::shared_ptr<Option> o2 = std::make_shared<Option>("o2");
        std::shared_ptr<Option> o3 = std::make_shared<Option>("o3");
        std::shared_ptr<Option> o4 = std::make_shared<Option>("o4");
        SingleChoicePoll p = SingleChoicePoll("poll", std::make_shared<RelativePercentage>());
        BOOST_CHECK_EQUAL(p.getPollName(), "poll");
        p.addOption(o1);
        p.addOption(o2);
        p.addOption(o3);
        p.addOption(o4);
        BOOST_CHECK_EQUAL(p.getOptionsNumber(), 4);
        p.removeLastOption();
        BOOST_CHECK_EQUAL(p.getOptionsNumber(), 3);
    }

    BOOST_AUTO_TEST_CASE(SinglePollTest) {
        std::shared_ptr<Option> o1 = std::make_shared<Option>("o1");
        std::shared_ptr<Option> o2 = std::make_shared<Option>("o2");
        std::shared_ptr<Option> o3 = std::make_shared<Option>("o3");
        SingleChoicePoll sp = SingleChoicePoll("poll", std::make_shared<RelativePercentage>());
        sp.addOption(o1);
        sp.addOption(o2);
        sp.addOption(o3);
        std::shared_ptr<Voter> v1 = std::make_shared<Voter>(1);
        std::shared_ptr<Voter> v2 = std::make_shared<Voter>(1);
        std::shared_ptr<SingleVote> sv1 = std::make_shared<SingleVote>(v1);
        std::shared_ptr<SingleVote> sv2 = std::make_shared<SingleVote>(v2);
        sv1->makeChoice(1);
        sv2->makeChoice(1);
        sp.addVote(sv1);
        sp.addVote(sv2);
        BOOST_CHECK_EQUAL(sp.getVotesNumber(), 2);
        sp.countVotes();
        BOOST_CHECK_EQUAL(sp.getOptionCounter(o1), 2);
        BOOST_CHECK_EQUAL(sp.getOptionCounter(o3), 0);
    }

    BOOST_AUTO_TEST_CASE(MultiPollTest) {
        std::shared_ptr<Option> o1 = std::make_shared<Option>("o1");
        std::shared_ptr<Option> o2 = std::make_shared<Option>("o2");
        std::shared_ptr<Option> o3 = std::make_shared<Option>("o3");
        MultiChoicePoll mp = MultiChoicePoll("poll", std::make_shared<RelativePercentage>());
        mp.addOption(o1);
        mp.addOption(o2);
        mp.addOption(o3);
        std::shared_ptr<Voter> v1 = std::make_shared<Voter>(1);
        std::shared_ptr<Voter> v2 = std::make_shared<Voter>(2);
        std::shared_ptr<MultiVote> mv1 = std::make_shared<MultiVote>(v1);
        std::shared_ptr<MultiVote> mv2 = std::make_shared<MultiVote>(v2);
        mv1->makeChoice(1);
        mv1->makeChoice(2);
        mv2->makeChoice(1);
        mp.addVote(mv1);
        mp.addVote(mv2);
        mp.countVotes();
        BOOST_CHECK_EQUAL(mp.getVotesNumber(), 2);
        BOOST_CHECK_EQUAL(mp.getOptionCounter(o1), 2);
        BOOST_CHECK_EQUAL(mp.getOptionCounter(o3), 0);
    }

    BOOST_AUTO_TEST_CASE(IncorectVotesTest) {
        std::shared_ptr<Option> o1 = std::make_shared<Option>("o1");
        SingleChoicePoll sp = SingleChoicePoll("poll", std::make_shared<RelativePercentage>());
        MultiChoicePoll mp = MultiChoicePoll("poll", std::make_shared<RelativePercentage>());
        mp.addOption(o1);
        sp.addOption(o1);

        BOOST_CHECK_EQUAL(sp.getIncorrectVotes(), 0);

        std::shared_ptr<Voter> vs1 = std::make_shared<Voter>(1);
        std::shared_ptr<Voter> vs2 = std::make_shared<Voter>(2);
        std::shared_ptr<Voter> vs3 = std::make_shared<Voter>(3);

        std::shared_ptr<Voter> vm1 = std::make_shared<Voter>(1);
        std::shared_ptr<Voter> vm2 = std::make_shared<Voter>(2);
        std::shared_ptr<Voter> vm3 = std::make_shared<Voter>(3);

        std::shared_ptr<SingleVote> sv1 = std::make_shared<SingleVote>(vs1);
        std::shared_ptr<SingleVote> sv2 = std::make_shared<SingleVote>(vs2);
        std::shared_ptr<SingleVote> sv3 = std::make_shared<SingleVote>(vs3);

        std::shared_ptr<MultiVote> mv1 = std::make_shared<MultiVote>(vm1);
        std::shared_ptr<MultiVote> mv2 = std::make_shared<MultiVote>(vm2);
        std::shared_ptr<MultiVote> mv3 = std::make_shared<MultiVote>(vm3);

        sv1->makeChoice(1);
        sv2->makeChoice(4);
        sp.addVote(sv1);
        sp.addVote(sv2);
        sp.addVote(sv3);

        mv1->makeChoice(1);
        mv1->makeChoice(4);
        mv2->makeChoice(4);
        mp.addVote(mv1);
        mp.addVote(mv2);
        mp.addVote(mv3);

        sp.countVotes();
        mp.countVotes();
        BOOST_CHECK_EQUAL(sp.getIncorrectVotes(), 2);
        BOOST_CHECK_EQUAL(mp.getIncorrectVotes(), 3);
        sp.resetIncorrectVotes();
        BOOST_CHECK_EQUAL(sp.getIncorrectVotes(), 0);
    }

    BOOST_AUTO_TEST_CASE(LoopTest) {
        SingleChoicePoll p = SingleChoicePoll("poll", std::make_shared<RelativePercentage>());
        auto o = std::make_shared<Option>("option");
        p.addOption(o);

        for(unsigned short i = 0; i < 5; i++){
            auto v = std::make_shared<SingleVote>(std::make_shared<Voter>(i));
            v->makeChoice(1);
            p.addVote(v);
        }
        p.countVotes();
        BOOST_CHECK_EQUAL(p.getOptionCounter(o), 5);
    }

BOOST_AUTO_TEST_SUITE_END()