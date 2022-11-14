#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <cstdint>
#include <memory>
#include <stack>
#include "Node.h"

using namespace std;


template<class I> BST<I>::BST() 
{
    root = nullptr;
}

template <class I> BST<I>::~BST()
{
    clearTree();
}

template <class I> void BST<I>::insert(std::shared_ptr<Node<I>> item)
{
    std::shared_ptr<Node<I>> temp = root;
    
    if(root == nullptr)
    {
        root = item;
        //cout<<"set head\n";
        return;
    }

    while(root != nullptr)
    {
        if (item->getItem() > temp->getItem() && temp->getRight() == nullptr){
            temp->setRight(item);
             //cout<<"place right\n";
            //cout<<"break\n";
            break;
        }else if (item->getItem() < temp->getItem() && temp->getLeft() == nullptr){
            temp->setLeft(item);
            //cout<<"place left\n";
            //cout<<"break\n";
            break;
        }
        else if (item->getItem() == temp->getItem() && temp->getLeft() == nullptr){
            //temp->setRight(item);
            //cout<<"same numba\n";
            //cout<<"break\n";
            break;
        }
        else if (item->getItem() > temp->getItem()){
            temp = temp->getRight();
        cout<<"move right\n";
        }else if (item->getItem() < temp->getItem()){
            temp = temp->getLeft();
            //cout<<"move left\n";
        }
        else if(item->getItem() == temp->getItem())
        {
            //cout << "same number\n";
            //cout<<"break\n";
            break;
        }
    }

    
    

}


template <class I> std::shared_ptr<Node<I>> BST<I>::find(I target)
{
    
    std::shared_ptr<Node<I>> temp = root;
    
    if (root == nullptr){
        //cout << "Could't find yo number: " << target <<endl;
        return nullptr;
    }
    bool found = false;
    while(found == false){
    
    if (temp->getItem() == target){
        //std::cout << target << " is in fact " << temp->getItem() << std::endl;
        return temp;
    }
    else if (target < temp->getItem()){
        temp = temp->getLeft();
        
    }else if (target > temp->getItem()){
        temp = temp->getRight();
    }
    }
    return nullptr;
    
    
}


template <class I> int BST<I>::size()
{
    std::shared_ptr<Node<I>> temp = root;
    int count = 0;
    stack<std::shared_ptr<Node<I>>> s;
    bool end = false;
    while(temp != nullptr||s.empty() == false) 
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->getLeft();
            count++;
        }
        temp = s.top();
        s.pop();
        temp = temp->getRight();
        

    }

    return count;
}

template <class I> std::stack<I> BST<I>::GetAllAscending()
{
    std::shared_ptr<Node<I>> temp = root;
    int count = 0;
    std::stack<I> s;
    stack<std::shared_ptr<Node<I>>> ss;
    while(temp != nullptr||ss.empty() == false) 
    {
        while (temp != nullptr)
        {
            s.push(temp->getItem());
            ss.push(temp);
            temp = temp->getLeft();
            count++;
        }
        temp = ss.top();
        //s.pop();
        ss.pop();
        temp = temp->getRight();
        

    }
    std::stack<I> r;
    r.push(s.top());
    s.pop();
    while (!s.empty())
    {
        r.push(s.top());
        s.pop();
    }
    return r;
}

template <class I> void BST<I>::clearTree()
{
    root = nullptr;
}