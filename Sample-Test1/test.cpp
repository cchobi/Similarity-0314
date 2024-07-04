#include "pch.h"
#include "../Similar/similar.cpp"
#include <vector>

using namespace std;

class SimilarFixture : public testing::Test {
public:
	Similar sim;
};

TEST_F(SimilarFixture, TestLengthSame) {
	int result = sim.checkCharNums("ASD", "DSA");
	EXPECT_EQ(result, 60);
}

TEST_F(SimilarFixture, TestLengthDifferent1) {
	int result = sim.checkCharNums("A", "BB");
	EXPECT_EQ(result, 0);
}

TEST_F(SimilarFixture, TestLengthDifferent2) {
	int result = sim.checkCharNums("AAABB", "BAA");
	EXPECT_EQ(result, 19);
}

TEST_F(SimilarFixture, TestLengthDifferent3) {
	int result = sim.checkCharNums("AA", "AAE");
	EXPECT_EQ(result, 30);
}

TEST_F(SimilarFixture, TestAlphaSame) {
	int expected = 40;
	int result = sim.checkAlpha("ASD", "DSA");
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarFixture, TestAlphaDiff1) {
	int expected = 0;
	int result = sim.checkAlpha("A", "BB");
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarFixture, TestAlphaDiff2) {
	int expected = 40;
	int result = sim.checkAlpha("AAABB", "BA");
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarFixture, TestAlphaDiff3) {
	int expected = 20;
	int result = sim.checkAlpha("AA", "AAE");
	EXPECT_EQ(result, expected);
}


