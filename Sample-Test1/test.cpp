#include "pch.h"
#include "../Similar/similar.cpp"
#include <vector>

using namespace std;

class SimilarFixture : public testing::Test {
public:
	Similar sim;
};

TEST_F(SimilarFixture, TestLengthSame) {
	string str1 = "ASD";
	string str2 = "DSA";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 60);
}

TEST_F(SimilarFixture, TestLengthDifferent1) {
	string str1 = "A";
	string str2 = "BB";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 0);
}

TEST_F(SimilarFixture, TestLengthDifferent2) {
	string str1 = "AAABB";
	string str2 = "BAA";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 19);
}

TEST_F(SimilarFixture, TestLengthDifferent3) {
	string str1 = "AA";
	string str2 = "AAE";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 30);
}

TEST_F(SimilarFixture, TestAlphaSame) {
	string str1 = "ASD";
	string str2 = "DSA";
	int expected = 40;

	int result = sim.checkAlpha(str1, str2);
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarFixture, TestAlphaDiff1) {
	string str1 = "A";
	string str2 = "BB";
	int expected = 0;

	int result = sim.checkAlpha(str1, str2);
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarFixture, TestAlphaDiff2) {
	string str1 = "AAABB";
	string str2 = "BA";
	int expected = 40;

	int result = sim.checkAlpha(str1, str2);
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarFixture, TestAlphaDiff3) {
	string str1 = "AA";
	string str2 = "AAE";
	int expected = 20;

	int result = sim.checkAlpha(str1, str2);
	EXPECT_EQ(result, expected);
}


