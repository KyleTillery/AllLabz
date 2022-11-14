//#pragma once
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <stack>
#include "Node.h"





template <class I> class BST
{
    protected:
        
    public:
        BST();
        void insert(std::shared_ptr<Node<I>> node);
        std::shared_ptr<Node<I>> find(I target);
        int size();
        std::stack<I> GetAllAscending();
        void clearTree();
        ~BST();
        private:
        std::shared_ptr<Node<I>> root;
	    
};

#include "BST.cpp"