// StackQueues.cpp : Defines the exported functions for the DLL application.
//
//#include "StackQueue.h"
#include <string>
#include <iostream>
#include <array>


using namespace std;


template <class ItemType> ArrayBasedStack<ItemType>::~ArrayBasedStack()
{

}

template <class ItemType> ArrayBasedStack<ItemType>::ArrayBasedStack()
{

}

template <class ItemType> bool ArrayBasedStack<ItemType>::isEmpty() const
{
	if (s_count == 0){
		return true;
	}
	return false;
}

template <class ItemType> bool ArrayBasedStack<ItemType>::push(const ItemType & val)
{
	if (s_count < 9){
		arraystack[s_count] = val;
		s_count = s_count + 1;
		return true;
	}else{
		return false;
	}
}

template <class ItemType> bool ArrayBasedStack<ItemType>::pop()
{
	if (s_count != 0){
		arraystack[s_count] = 0;
		s_count = s_count - 1;
		return true;
	}else{
	return false;
	}
}

template <class ItemType> int ArrayBasedStack<ItemType>::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return arraystack[s_count-1];
		//TODO
	}


}

template <class ItemType> std::string ArrayBasedStack<ItemType>::toString() const
{
	std:string str;
	for(int i = 0; i < s_count; i++)
	{
		if(s_count == 0)
			return str;
		if(i != s_count -1)
			str = str + std::to_string(arraystack[i]) + " ";
		else
			str = str + std::to_string(arraystack[i]);
	}
	return str;
}

template <class ItemType> ArrayBasedQueue<ItemType>::~ArrayBasedQueue()
{

}

template <class ItemType> ArrayBasedQueue<ItemType>::ArrayBasedQueue()
{

}

template <class ItemType> bool ArrayBasedQueue<ItemType>::isEmpty() const
{
	if (q_count == 0){
		return true;
	}
	else
		return false;
}

template <class ItemType> bool ArrayBasedQueue<ItemType>::enQueue(const ItemType &val)
{
	if(q_count < 9)
	{
		arrayqueue[q_count] = val;
		q_count++;
		return true;
	}
	else
		return false;
}

template <class ItemType> bool ArrayBasedQueue<ItemType>::deQueue()
{
	if (q_count > 0){
		for (int i = 0; i < q_count; i++){
			arrayqueue[i] = arrayqueue[i+1];
		}
		arrayqueue[q_count] = "";
		q_count = q_count - 1;
		return true;
	}else{
		return false;
	}
}

template <class ItemType> std::string ArrayBasedQueue<ItemType>::toString() const
{
	std:string str;
	for(int i = 0; i < q_count; i++)
	{
		if(q_count == 0)
			return str;
		if(i != q_count -1)
			str = str + arrayqueue[i] + " ";
		else
			str = str + arrayqueue[i];
	}
	return str;
}

template <class ItemType> std::string ArrayBasedQueue<ItemType>::peekFront() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return arrayqueue[0];
		//TODO
	}


}




