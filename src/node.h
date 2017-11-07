#ifndef _nodecpp_h_
#define _nodecpp_h_
namespace julian
{
template <typename T>
class SingleLinkedNode
{
	T m_data;
	SingleLinkedNode<T> *m_nxt;
public:
	explicit SingleLinkedNode(const T&, SingleLinkedNode<T> *pLink = nullptr);
	explicit SingleLinkedNode(T&&, SingleLinkedNode<T> *pLink = nullptr);

	~SingleLinkedNode();
	
	
	void setData(const T&);
	void setNodeToLink(SingleLinkedNode<T>*);
	
	T& getData();
	SingleLinkedNode<T>* getNextNode();
	
	bool hasLink();

};	
}

#endif /* _nodecpp_h_ */