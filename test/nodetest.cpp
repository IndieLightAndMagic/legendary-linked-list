#include "node.h"
#include "gtest/gtest.h"

namespace {

class SingleLinkedNodeTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		n1 = new julian::SingleLinkedNode<int>(0xaf);
		n0 = new julian::SingleLinkedNode<int>(0xab, n1);
	}
	julian::SingleLinkedNode<int> *n0;
	julian::SingleLinkedNode<int> *n1;

	virtual void TearDown()
	{
		delete n0;
		delete n1;
	}
};

TEST_F(SingleLinkedNodeTest, n0haslink)
{
	EXPECT_EQ(nullptr, n1->getNextNode());
	EXPECT_NE(nullptr, n0->getNextNode());
}
} //testingFixture
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

