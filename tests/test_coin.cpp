// test_coin.cpp
#include <gtest/gtest.h>
#include "coin.hpp"

TEST(CoinBasics, DefaultConstructsToZero) {
    Coin c;
    EXPECT_EQ(c.copper,   0);
    EXPECT_EQ(c.silver,   0);
    EXPECT_EQ(c.gold,     0);
    EXPECT_EQ(c.platinum, 0);
}

TEST(CoinBasics, ValueConstructorSetsFields) {
    Coin c(3, 2, 1, 0);
    EXPECT_EQ(c.copper,   3);
    EXPECT_EQ(c.silver,   2);
    EXPECT_EQ(c.gold,     1);
    EXPECT_EQ(c.platinum, 0);
}

TEST(CoinOps, PlusAddsPerDenomination) {
    Coin a(10, 0, 0, 0);
    Coin b(5,  2, 0, 0);

    Coin s = a + b;
    EXPECT_EQ(s.copper,   15);
    EXPECT_EQ(s.silver,   2);
    EXPECT_EQ(s.gold,     0);
    EXPECT_EQ(s.platinum, 0);
}

TEST(CoinOps, MinusSubtractsPerDenomination) {
    Coin a(10, 3, 1, 0);
    Coin b(5,  2, 0, 0);

    Coin d = a - b;
    EXPECT_EQ(d.copper,   5);
    EXPECT_EQ(d.silver,   1);
    EXPECT_EQ(d.gold,     1);
    EXPECT_EQ(d.platinum, 0);
}

TEST(CoinOps, PlusEqualsMutatesLeft) {
    Coin a(10, 0, 0, 0);
    Coin b(5,  2, 0, 0);

    a += b;
    EXPECT_EQ(a.copper,   15);
    EXPECT_EQ(a.silver,   2);
    EXPECT_EQ(a.gold,     0);
    EXPECT_EQ(a.platinum, 0);
}

TEST(CoinOps, MinusEqualsMutatesLeft) {
    Coin a(10, 3, 1, 0);
    Coin b(5,  2, 0, 0);

    a -= b;
    EXPECT_EQ(a.copper,   5);
    EXPECT_EQ(a.silver,   1);
    EXPECT_EQ(a.gold,     1);
    EXPECT_EQ(a.platinum, 0);
}

TEST(CoinCompare, EqualityAndInequality) {
    Coin a(1,2,3,4);
    Coin b(1,2,3,4);
    Coin c(1,2,3,5);

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
    EXPECT_FALSE(a == c);
}

// These tests assume that the comparison operators are defined to compare total value.
TEST(CoinCompare, OrderingByTotalValue_Assumption) {
    Coin cheap(10, 0, 0, 0);   // 10 copper
    Coin pricy(0, 1, 0, 0);    // 1 silver (should be > 10 copper in most systems)

    // If you intend <, <=, >, >= to compare by total value, these should hold:
    EXPECT_FALSE(cheap < pricy);
    EXPECT_FALSE(pricy > cheap);
    EXPECT_TRUE(cheap <= pricy);
    EXPECT_TRUE(pricy <= cheap);
    EXPECT_TRUE(pricy >= cheap);
    EXPECT_TRUE(cheap >= pricy);
}

// If you expose totalWeight() / totalValueInCopper(), add direct tests here.
// Without knowing your exact conversion/weight scheme, we only assert type/usage compiles.
TEST(CoinValues, ValueAndWeightCompileSmokeTest) {
    Coin a(10,20,20,50);
    EXPECT_TRUE(a.totalWeight() == 2.0); 
    EXPECT_TRUE(a.totalValueInCopper() ==  (10 + 20*10 + 20*100 + 50*1000));
}

// Test assignment operator and copy constructor
TEST(CoinCopy, CopyConstructorAndAssignment) {  
    Coin original(7, 8, 9, 10);
    Coin copyConstructed(original);  // Copy constructor
    EXPECT_EQ(copyConstructed.copper,   7);
    EXPECT_EQ(copyConstructed.silver,   8);
    EXPECT_EQ(copyConstructed.gold,     9);
    EXPECT_EQ(copyConstructed.platinum, 10);

    Coin assigned;
    assigned = original;  // Assignment operator
    EXPECT_EQ(assigned.copper,   7);
    EXPECT_EQ(assigned.silver,   8);
    EXPECT_EQ(assigned.gold,     9);
    EXPECT_EQ(assigned.platinum, 10);
}
