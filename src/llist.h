#include "node.h"
namespace julian
{


template <typename T>
class SingleLinkedList
{
	size_t m_count;
	SingleLinkedNode<T>* m_frontNode;
	SingleLinkedNode<T>* m_backNode;
public:
	SingleLinkedList();
	~SingleLinkedList();
	SingleLinkedNode<T>* front();
	SingleLinkedNode<T>* back();
	bool empty();
	size_t count();
	void clear();
	void insert(const T&, unsigned int pos);
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();

};

}

