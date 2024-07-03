#include "pch.h"
#include "../Similar/similar.cpp"
#include <vector>

using namespace std;

TEST(TestCaseName, TestLengthSame) {
	Similar sim;
	string str1 = "ASD";
	string str2 = "DSA";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 60);
}

TEST(TestCaseName, TestLengthDifferent1) {
	Similar sim;
	string str1 = "A";
	string str2 = "BB";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 0);
}

TEST(TestCaseName, TestLengthDifferent2) {
	Similar sim;
	string str1 = "AAABB";
	string str2 = "BAA";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 19);
}

TEST(TestCaseName, TestLengthDifferent3) {
	Similar sim;
	string str1 = "AA";
	string str2 = "AAE";

	int result = sim.checkCharNums(str1, str2);
	EXPECT_EQ(result, 30);
}
