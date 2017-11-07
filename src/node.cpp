#include <memory>

#include "node.h"
namespace julian
{
template <typename T>
SingleLinkedNode<T>::SingleLinkedNode(const T &rdata, SingleLinkedNode<T> *pLink):
	m_data(rdata),
	m_nxt(pLink)
{

}
template <typename T>
SingleLinkedNode<T>::SingleLinkedNode(T&&rdata, SingleLinkedNode<T> *pLink):
	m_data(std::move(rdata)),
	m_nxt(pLink)
{

}

template <typename T>
SingleLinkedNode<T>::~SingleLinkedNode()
{

}
template <typename T>
void SingleLinkedNode<T>::setData(const T &data)
{
	m_data = data;
}
template <typename T>
void SingleLinkedNode<T>::setNodeToLink(SingleLinkedNode<T> *pLink)
{
	m_nxt = pLink;
}
template <typename T>
T& SingleLinkedNode<T>::getData()
{
	return m_data;
}
template <typename T>
SingleLinkedNode<T>* SingleLinkedNode<T>::getNextNode()
{
	return m_nxt;
}
template class julian::SingleLinkedNode<int>;

}


