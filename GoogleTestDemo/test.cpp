#include "pch.h"
#include "vector"
#include "queue"
#include <numeric>

//------------------------------------------------Example 1 ------------------------------------------------------------//
/*
TEST(TestVectors, TestVectorOkay) {
	std::vector<int> x = std::vector<int>{ 1,0,1 };
	std::vector<int> y = std::vector<int>{ 1,0,1 };
	ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

	for (int i = 0; i < x.size(); ++i) {
		EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
	}
}
/**/


//After failed assert testing stops and this is important in this case, otherwise there would be exception thrown
/*
TEST(TestVectors, TestVectorsEqual) {
	std::vector<int> x = std::vector<int>{ 1,1,1,1,1 };
	std::vector<int> y = std::vector<int>{ 1,0,1 };
	//ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

	for (int i = 0; i < x.size(); ++i) {
		EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
	}
}
/**/


//If we use EXPECT we will get all broken EXPECT_* (before first broken ASSERT)
/*
TEST(TestVectors, TestVectorsDiffer) {
	std::vector<int> x = std::vector<int>{ 1,1,1,0 };
	std::vector<int> y = std::vector<int>{ 1,0,1,1 };
	ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

	for (int i = 0; i < x.size(); ++i) {
		EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
	}
}
/**/

//------------------------------------------------Example 2 -----------------------------------------------------//
/*
TEST(TestString, TestStringsFail) {
	int x = 1;
	switch (x) {
	case 1:
		ASSERT_FALSE(x != 1);
	default:
		FAIL() << "We shouldn't get here.";
	}
}
/**/   


//------------------------------------------------Example 3 -----------------------------------------------------//
/*
class QueueTest : public ::testing::Test {
protected:
	void SetUp() override {
		q1_.emplace(1);
		q2_.emplace(2);
		q2_.emplace(3);
	}

	// void TearDown() override {}

	std::queue<int> q0_;
	std::queue<int> q1_;
	std::queue<int> q2_;
};
TEST_F(QueueTest, IsEmptyInitially) {
	EXPECT_EQ(q0_.size(), 0);
}


TEST_F(QueueTest, DequeueWorks) {

	int n = 0;
	EXPECT_NO_THROW(n = q1_.front(); q1_.pop(););
	
	EXPECT_EQ(n, 1);
	EXPECT_EQ(q1_.size(), 0);

	EXPECT_NO_THROW(n = q2_.front(); q2_.pop(););
	EXPECT_EQ(n, 2);
	EXPECT_EQ(q2_.size(), 1);
}

TEST_F(QueueTest, Independence) {
	int n;
	EXPECT_NO_THROW(n = q2_.front(); q2_.pop(););
	EXPECT_EQ(n, 2);
	EXPECT_EQ(q2_.size(), 1);
}

TEST_F(QueueTest, Errors) {
	EXPECT_ANY_THROW(throw("error"));
	//EXPECT_ANY_THROW(q0_.back());
}
/**/
//------------------------------------------------Example 4 -----------------------------------------------------//
//*
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool MutuallyPrime(int m, int n) {
	return gcd(m, n) == 1;
}

TEST(TestNumbers, TestNumbersPredicate) {
	const int a = 3;
	const int b = 4;
	const int c = 10;
	EXPECT_PRED2(MutuallyPrime, a, b);  // Succeeds
	EXPECT_PRED2(MutuallyPrime, b, c);  // Fails
}
/**/