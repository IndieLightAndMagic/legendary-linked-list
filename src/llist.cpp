#include <utility>
#include "llist.h"

namespace julian
{


template <typename T>
SingleLinkedList<T>::SingleLinkedList():
	m_count(0),
	m_frontNode(nullptr),
	m_backNode(nullptr)
{

}
template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{

}
template <typename T>
SingleLinkedNode<T>* SingleLinkedList<T>::front()
{
	return m_frontNode;
}
template <typename T>
SingleLinkedNode<T>* SingleLinkedList<T>::back()
{
	return m_backNode;
}
template <typename T>
bool SingleLinkedList<T>::empty()
{
	auto isEmpty = m_count == 0;
	return isEmpty;
}
template <typename T>
size_t SingleLinkedList<T>::count()
{
	return m_count;
}
template <typename T>
void SingleLinkedList<T>::pop_front()
{
	auto pnode = m_frontNode;
	m_frontNode = m_frontNode->getNextNode();
	m_backNode = m_frontNode ? m_backNode : nullptr;
	delete pnode;
	--m_count;
}
template <typename T>
void SingleLinkedList<T>::pop_back()
{
	auto pnode = m_frontNode;
	if (pnode == m_backNode)
	{
		pop_front();
		return;
	}
	while (pnode->getNextNode() != m_backNode)
	{
		pnode = pnode->getNextNode;
	}
	std::swap(pnode,m_backNode);
	delete pnode;
	m_backNode->setNodeToLink(nullptr);
	--m_count;
}
template <typename T>
void SingleLinkedList<T>::clear()
{
	while(m_count){
		pop_front();
	}
}
template <typename T>
void SingleLinkedList<T>::push_front(const T &data)
{
	auto pnode = new SingleLinkedNode<T>(data);
	pnode->setNodeToLink(m_frontNode->getNextNode());
	m_frontNode = pnode;
	++m_count;
}
template <typename T>
void SingleLinkedList<T>::push_back(const T &data)
{
	auto pnode = new SingleLinkedNode<T>(data);
	m_backNode = pnode;
	++m_count;
}

}
