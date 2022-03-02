#include <boost/test/unit_test.hpp>
#include "DataStorage.h"

BOOST_AUTO_TEST_SUITE(DataTests)

    BOOST_AUTO_TEST_CASE(SaveValues) {
        std::string p="/home/student/oop21_ww_01/project/library/src/dane.txt";
        std::vector<float> v {40, 30, 10, 20};
        std::vector<std::string> s {"o1", "o2", "o3", "o4"};
        DataStorage dataStorage;
        dataStorage.SaveToFile(p, v, s);
    }

    BOOST_AUTO_TEST_CASE(ReadValuesTest) {
        std::string p="/home/student/oop21_ww_01/project/library/src/dane.txt";
        std::vector<float> v1 {40, 30, 10, 20};
        std::vector<float> v2 {};
        DataStorage dataStorage;
        v2 = dataStorage.readValues(p);
        BOOST_CHECK_EQUAL(v1.size(), v2.size());
        BOOST_CHECK_EQUAL(v1[2], v2[2]);
    }

    BOOST_AUTO_TEST_CASE(ReadNamesTest) {
        std::string p="/home/student/oop21_ww_01/project/library/src/dane.txt";
        std::vector<std::string> s1 {"o1", "o2", "o3", "o4"};
        std::vector<std::string> s2 {};
        DataStorage dataStorage;
        s2 = dataStorage.readNames(p);
        BOOST_CHECK_EQUAL(s1.size(), s2.size());
        BOOST_CHECK_EQUAL(s1[2], s2[2]);
    }

BOOST_AUTO_TEST_SUITE_END()