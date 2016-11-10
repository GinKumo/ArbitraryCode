// --------------------
// StrategyPatternAC.c++
// --------------------

// https://en.wikipedia.org/wiki/Strategy_pattern

#include "gtest/gtest.h"

#include "StrategyPatternAC.h"

using namespace std;

TEST(Strategy_Pattern_Fixture, test_1) {
    Movie x("Lion King", "ChildrensPrice", 2);
    ASSERT_EQ(2, x.amount());}

TEST(Strategy_Pattern_Fixture, test_2) {
    Movie x("Finding Nemo", "ChildrensPrice", 4);
    ASSERT_EQ(4, x.amount());}

TEST(Strategy_Pattern_Fixture, test_3) {
    Movie x("Jason Bourne", "NewReleasePrice", 2);
    ASSERT_EQ(6, x.amount());}

TEST(Strategy_Pattern_Fixture, test_4) {
    Movie x("Giant", "RegularPrice", 1);
    ASSERT_EQ(2, x.amount());}

TEST(Strategy_Pattern_Fixture, test_5) {
    Movie x("Shane", "RegularPrice", 3);
    ASSERT_EQ(4, x.amount());}
