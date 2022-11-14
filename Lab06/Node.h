#pragma once

#include <memory>

template<class ItemType>
class Node
{
private:
	ItemType m_value;
	std::shared_ptr<Node<ItemType>>  m_right;
	std::shared_ptr<Node<ItemType>>  m_left;

public:
	Node() = delete;
	Node(ItemType val);
	void setLeft(std::shared_ptr<Node<ItemType>> nextNodePtr);
	void setRight(std::shared_ptr<Node<ItemType>> nextNodePtr);
	int getItem() const;
	std::shared_ptr<Node<ItemType>> getRight() const;
	std::shared_ptr<Node<ItemType>> getLeft() const;
	virtual ~Node();
	
};

#include "Node.cpp"