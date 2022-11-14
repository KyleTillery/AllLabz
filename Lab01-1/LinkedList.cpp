// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <array>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}
bool ILinkedList::isEmpty() const
{
	//TODO - hint use m_count
	if(m_count == 0)
		return true;
	else
		return false;
	
}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
	// Otherwise you need to delete each node individuall in the owner of the Nodes (i.e. the LinkedList)
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}

/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	if(m_count >= 11)
		return false;
	
	Node* newNode = new Node();
	newNode->setItem(val);
	newNode->setNext(nullptr);
	if(m_head == nullptr)
	{
		m_head = newNode;
	}
	else
	{
		Node* temp = m_head;
		while(temp->getNext() != nullptr)
			temp = temp->getNext();
		temp->setNext(newNode);
	}
	m_count = m_count + 1;
	return true;	

	//TODO
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node* temp = m_head;
	Node* prev;
	if(m_count == 0)
	{
		return false;
	}
	while ((temp != nullptr) && (temp->getItem() != val))
	{
		prev = temp;
		temp = temp->getNext();	
	}
	if (temp == nullptr){
		return false;
	}
	if (val == 1){
		m_head = m_head->getNext();
	}else{
		prev->setNext(temp->getNext());
		temp = nullptr;
		delete temp;
	}
	m_count = m_count - 1;

	
	
	//TODO
	return true;

}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	Node* cur = m_head;
	Node* next = nullptr;

	while (cur != nullptr)
	{
		next = cur->getNext();
		free(cur);
		cur = next;
	}

	m_head = nullptr;
	m_count = 0;
	
    //TODO
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	std::string str = "";
	
	Node* cur = m_head;
	int num;
	if(m_count > 0)
	{
	for (int i = 0; i <= m_count; i++)
	{
		if(cur != nullptr)
		{
			
			num = cur->getItem();
			if(i != m_count - 1)
				str = str + std::to_string(num) + " ";
			else
				str = str + std::to_string(num);
			cur = cur->getNext();
			
		}
		
	}
	}
	

    //TODO
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0;
	// you got it for free :)
}

bool ArrayBasedLinkedList::add(int val)
{
	if (m_count > 9)
	{
		return false;
	}
	m_values[m_count] = val;
	m_count = m_count + 1;
	return true;
	//TODO
}
bool ArrayBasedLinkedList::remove(int val)
{
	for(int i=0; i <= m_count; i++)
	{
		if (m_values[i] == val)
		{
			for (i ; i < m_count; i++)
			{
				m_values[i] = m_values[i+1];
			}
			m_values[m_count] = 0;
			m_count = m_count - 1;
			return true;
			break;
		}
	}
	//TODO
	return false;
}
void ArrayBasedLinkedList::clear()
{
	
	for(int i=0; i <= m_count; i++)
	{
		m_values[i] = 0;
	}
	m_count = 0;
	
	//TODO
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	std:string str = "";
	//TODO
	for (int i = 0; i < m_count; i++)
	{
		if(m_count == 0)
			return str;
		if(i != m_count -1)
			str = str + std::to_string(m_values[i]) + " ";
		else
			str = str + std::to_string(m_values[i]);
	}

	return str;
}
