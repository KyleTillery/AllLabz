#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <bits/stdc++.h>
//#include "hashTable.h"

using namespace std;
template <typename v, typename k>
class hashNode
{
    public:
        v value;
        k key;

        hashNode(v value, k key)
        {
            this->value = value;
            this->key = key;
        }
};


template <typename v, typename k>
class hashTable
{
    public:



    
    ~hashTable()
    {
        delete(arr);
    }
    
    hashTable(int m)
    {
        this->max_size = m;
        size = 0;
        arr = new hashNode<v, k>*[m];
        for (int i = 0; i < m; i++)
        arr[i] = NULL;
        temp = new hashNode<v, k>(-1, -1);
    }

    int hash(k key)
    {
        int return_value;
        int temp = (int)key;
        return_value = temp % max_size;
        return return_value;
    }
    int hashCode(k key)
    {
        return 0;
    }
    
    void add(v val, k key)
    {
        hashNode<v, k>* tempy = new hashNode<v, k>(val, key);

        int hashIndex = hashCode(key);
        if (size + 1 > max_size)
            return;
        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= max_size;
        }

        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = tempy;
    }
    
    v getItem(int key)
    {
        int hashIndex = hashCode(key);
        int counter = 0;

        while (arr[hashIndex] != NULL) {
        
            if (counter++ > max_size)
                return NULL;

            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= max_size;
        }
        return NULL;
    }
    
    int contains()
    {
        return size;
    }

    protected:
        list<v> *hashlist;
        int max_size;
        hashNode<v, k>** arr;
        hashNode<v, k>* temp;
        int size;
};
