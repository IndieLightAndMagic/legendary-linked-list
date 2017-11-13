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
		pnode = pnode->getNextNode();
	}
	std::swap(pnode,m_backNode);
	m_backNode->setNodeToLink(nullptr);
	
	delete pnode;
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
void SingleLinkedList<T>::insert(const T &data, unsigned int pos)
{	
	//in the front
	if (!m_count || !pos) 
	{
		push_front(data);
		return;
	}

	//in the back
	if (pos >= m_count)
	{
		push_back(data);
		return;
	}
	
	//in the middle
	auto pNode = m_frontNode;
	for (auto index = 1; pNode && (index < pos); ++index)
	{
		pNode = pNode->getNextNode();
	}
	auto dataNode = new SingleLinkedNode<T>(data,pNode->getNextNode());
	pNode->setNodeToLink(dataNode);

}
template <typename T>
void SingleLinkedList<T>::push_front(const T &data)
{
	auto pnode = new SingleLinkedNode<T>(data);
	if (m_frontNode)
    {
        pnode->setNodeToLink(m_frontNode->getNextNode());
    }
    else
    {
        m_backNode = pnode;
    }
	m_frontNode = pnode;
	++m_count;
}
template <typename T>
void SingleLinkedList<T>::push_back(const T &data)
{
	auto pnode = new SingleLinkedNode<T>(data);
    if (m_backNode)
    {
        m_backNode->setNodeToLink(pnode);
    }
    else
    {
        m_frontNode = pnode;
    }
    m_backNode = pnode;
	++m_count;
}
template class julian::SingleLinkedList<int>;

}	
