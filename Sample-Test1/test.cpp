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
