#include <iostream>
#include "llist.h"
#include "gtest/gtest.h"

namespace {

class SingleLinkedListTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		n1 = new julian::SingleLinkedNode<int>(0xaf);
		n0 = new julian::SingleLinkedNode<int>(0xab, n1);

        l0 = new julian::SingleLinkedList<int>();
		l0->push_back(0x00);
		l0->push_back(0x01);
		l0->push_back(0x02);
		l0->push_back(0x03);
		l0->push_back(0x04);
		l0->push_back(0x05);
        while (l0->count())
        {
        	if (l0->count()%2)
        	{
        		l0->pop_front();
        	}
        	else
        	{
        		l0->pop_back();
        	}
        }
        
		l1 = new julian::SingleLinkedList<int>();
		l1->push_back(0x00);
		l1->push_back(0x01);
		l1->push_back(0x02);
		l1->push_back(0x03);
		l1->push_back(0x04);
		l1->push_back(0x05);

        l2 = new julian::SingleLinkedList<int>();
        l2->push_back(0x00);
        
	}
	julian::SingleLinkedNode<int> *n0;
	julian::SingleLinkedNode<int> *n1;
	julian::SingleLinkedList<int> *l0;
	julian::SingleLinkedList<int> *l1;
    julian::SingleLinkedList<int> *l2;

	virtual void TearDown()
	{
		delete n0;
		delete n1;
	}
};

TEST_F(SingleLinkedListTest, nodesLinkTest)
{
	EXPECT_EQ(nullptr,	n1->getNextNode());
	EXPECT_NE(nullptr,	n0->getNextNode());
}
TEST_F(SingleLinkedListTest, nodesDataTest)
{
	EXPECT_EQ(0xab,		n0->getData());
	EXPECT_EQ(0xaf,		n1->getData());
}
TEST_F(SingleLinkedListTest, nullListTest)
{
	EXPECT_EQ(0x00,		l0->count());
	EXPECT_EQ(nullptr,	l0->front());
	EXPECT_EQ(nullptr,	l0->back());
}
TEST_F(SingleLinkedListTest, sizedListTest)
{
	EXPECT_EQ(6,		l1->count());
	EXPECT_NE(nullptr,	l1->front());
	EXPECT_NE(nullptr,	l1->back());
}
TEST_F(SingleLinkedListTest, singleElemListTest)
{
    EXPECT_EQ(1,            l2->count());
    EXPECT_EQ(l2->back(),   l2->front());
}

} //testingFixture
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

