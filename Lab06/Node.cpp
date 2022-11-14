#include <iostream>
#include <memory>

template<class ItemType>
Node<ItemType>::Node(ItemType val) : m_value(val), m_right(nullptr), m_left(nullptr)
{

}


template<class ItemType>
void Node<ItemType>::setRight(std::shared_ptr<Node<ItemType>> nextNodePtr)
{
	m_right = nextNodePtr;
}

template<class ItemType>
void Node<ItemType>::setLeft(std::shared_ptr<Node<ItemType>> nextNodePtr)
{
	m_left = nextNodePtr;
}

template<class ItemType>
int Node<ItemType>::getItem() const
{
	return m_value;
}

template<class ItemType>
std::shared_ptr<Node<ItemType>>  Node<ItemType>::getRight() const
{
	return m_right;
}

template<class ItemType>
std::shared_ptr<Node<ItemType>>  Node<ItemType>::getLeft() const
{
	return m_left;
}

template<class ItemType>
Node<ItemType>::~Node()
{

}