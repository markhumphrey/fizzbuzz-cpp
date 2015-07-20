#include "gtest/gtest.h"
#include "divisible_check.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST(DivisibleCheckTest, NoDivisor) {
	DivisibleCheck divCheck;
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << 2 << endl << 3 << endl << 4 << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, OneDivisor) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << "a" << endl << 3 << endl << "a" << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, MultiDivisor) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	divCheck.addDivisor(4, "b");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << "a" << endl << 3 << endl << "ab" << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, DuplicateDivisor) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	divCheck.addDivisor(2, "a");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << "aa" << endl << 3 << endl << "aa" << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, ClearDivisors) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	divCheck.addDivisor(4, "b");
	divCheck.clearDivisors();
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << 2 << endl << 3 << endl << 4 << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, DivideByZero) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(0, "a");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << 2 << endl << 3 << endl << 4 << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, DivideByNegative) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(-2, "a");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << "a" << endl << 3 << endl << "a" << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, EmptyMessageDivisor) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << "" << endl << 3 << endl << "" << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, StartEqualsEnd) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	ostringstream out;
	divCheck.doCheck(1, 1, out);
	ostringstream expect;
	expect << 1 << endl;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, StartAfterEnd) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	ostringstream out;
	divCheck.doCheck(2, 1, out);
	ostringstream expect;
	EXPECT_EQ(expect.str(), out.str());
}

TEST(DivisibleCheckTest, ReuseDivisibleCheck) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(2, "a");
	ostringstream out;
	divCheck.doCheck(1, 4, out);
	ostringstream expect;
	expect << 1 << endl << "a" << endl << 3 << endl << "a" << endl;
	EXPECT_EQ(expect.str(), out.str());
	ostringstream out2;
	divCheck.doCheck(1, 4, out2);
	EXPECT_EQ(expect.str(), out2.str());
}

TEST(DivisibleCheckTest, CracklePop) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(3, "Crackle");
	divCheck.addDivisor(5, "Pop");
	ostringstream out;
	divCheck.doCheck(1, 100, out);
	ostringstream expect;
	expect << 1 << endl << 2 << endl << "Crackle" << endl << 4 << endl << "Pop"
			<< endl << "Crackle" << endl << 7 << endl << 8 << endl << "Crackle"
			<< endl << "Pop" << endl << 11 << endl << "Crackle" << endl << 13
			<< endl << 14 << endl << "CracklePop" << endl << 16 << endl << 17
			<< endl << "Crackle" << endl << 19 << endl << "Pop" << endl
			<< "Crackle" << endl << 22 << endl << 23 << endl << "Crackle"
			<< endl << "Pop" << endl << 26 << endl << "Crackle" << endl << 28
			<< endl << 29 << endl << "CracklePop" << endl << 31 << endl << 32
			<< endl << "Crackle" << endl << 34 << endl << "Pop" << endl
			<< "Crackle" << endl << 37 << endl << 38 << endl << "Crackle"
			<< endl << "Pop" << endl << 41 << endl << "Crackle" << endl << 43
			<< endl << 44 << endl << "CracklePop" << endl << 46 << endl << 47
			<< endl << "Crackle" << endl << 49 << endl << "Pop" << endl
			<< "Crackle" << endl << 52 << endl << 53 << endl << "Crackle"
			<< endl << "Pop" << endl << 56 << endl << "Crackle" << endl << 58
			<< endl << 59 << endl << "CracklePop" << endl << 61 << endl << 62
			<< endl << "Crackle" << endl << 64 << endl << "Pop" << endl
			<< "Crackle" << endl << 67 << endl << 68 << endl << "Crackle"
			<< endl << "Pop" << endl << 71 << endl << "Crackle" << endl << 73
			<< endl << 74 << endl << "CracklePop" << endl << 76 << endl << 77
			<< endl << "Crackle" << endl << 79 << endl << "Pop" << endl
			<< "Crackle" << endl << 82 << endl << 83 << endl << "Crackle"
			<< endl << "Pop" << endl << 86 << endl << "Crackle" << endl << 88
			<< endl << 89 << endl << "CracklePop" << endl << 91 << endl << 92
			<< endl << "Crackle" << endl << 94 << endl << "Pop" << endl
			<< "Crackle" << endl << 97 << endl << 98 << endl << "Crackle"
			<< endl << "Pop" << endl;
	EXPECT_EQ(expect.str(), out.str());
}

