#include "priorityQueue.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <array>

using namespace std;

priorityQueue::priorityQueue()
{

}

bool priorityQueue::isEmpty() const
{
    if(m_count == 0)
        return true;
    else
        return false;
}

HeapBased::HeapBased()
{

}

HeapBased::~HeapBased()
{

}

bool HeapBased::isEmpty()
{
    if (m_values[0] = 0)
        return true;
    else
        return false;
}

bool HeapBased::insert(int val) // set up the return false
{
    int count = 0;
    int idk = 0;
    bool up = true;
    int placeholder;
    int size = 4999;
    //for  (int i : m_values)
    for  (int i = 0; i < size; i++){
        if (m_values[i] == 0 && idk == 0){
            m_values[i] = val;
            idk = 1;
            break;
        }
        count++;
    }
    while(up == true){// sorting heap
        if (count%2 > 0){//left child
            if (m_values[count] > m_values[((count-1)/2)]){
                placeholder = m_values[((count-1)/2)];
                m_values[((count-1)/2)] = m_values[count];
                m_values[count] = placeholder;
                count = ((count-1)/2);
                up = true;
            }else{
                up = false;
            }
        }else if(count%2 == 0) {//right child
            if (m_values[count] > m_values[((count-2)/2)]){
                placeholder = m_values[((count-2)/2)];
                m_values[((count-2)/2)] = m_values[count];
                m_values[count] = placeholder;
                count = ((count-1)/2);
                up = true;
            }else {
                up = false;
            }
        }else {
            up = false;
        }
    }
    return true;
    
}

bool HeapBased::DeQueue()
{
    int val = m_values[0];
    int count = 0;
    int left, right;
    int c = 0;
    for (int i : m_values)
    {
        c++;
    }
    for  (int i = 0; i < sizeof(m_values); i++){
        if (m_values[i] == val){
            m_values[i] = 0;
            break;
        }
        if (m_values[i] == 0){
            return false;
        }
        count++;
    }
    left = 2 * count + 1;
    right = left + 1;
    while ((m_values[left] != 0 || m_values[right] != 0)){
        if (left > c || right > c || left + 1 > c || right*2+1 >c){
            break;
        }else if (m_values[left] > m_values[right] && left < c) {
            m_values[count] = m_values[left];
            m_values[left] = 0;
            count = left;
            left = 2 * left + 1;
        }else if (m_values[left] < m_values[right] && right < c){
            m_values[count] = m_values[right];
            m_values[right] = 0;
            count = right;
            left = 2 * right + 1;
        }
        right = left + 1;
    }
    return true;

    
}

std::string HeapBased::toString() const
{
    std::string queue;
    for (int i : m_values)
    {
        if (i != 0)
            queue = queue + " " + to_string(i);
        
    }
    return queue;
}

void ArrayBased::othersort(){
    
    int size = 0;
    int temp;
    for (int i : m_valuesother)
    {
        size++;
    }
    if (m_valuesother[0] == 0){
        for (int i = 0; i < size-1; i++){
            m_valuesother[i] = m_valuesother[i+1];
        }
    }
    for (size; size > 0; size--){
        if (m_valuesother[size] > m_valuesother[size-1] && m_valuesother[size] != 0 && m_valuesother[size-1] != 0){
            temp = m_valuesother[size];
            m_valuesother[size] =m_valuesother[size-1];
            m_valuesother[size-1] = temp;
        }
    }
    /*
    int n = size / sizeof(m_valuesother[0]);
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (m_valuesother[j] < m_valuesother[j + 1]){
                int temp = m_valuesother[j];
                    m_valuesother[j] = m_valuesother[j + 1];
                    m_valuesother[j + 1] = temp;
            }*/
}

ArrayBased::ArrayBased()
{

}

ArrayBased::~ArrayBased()
{

}

bool ArrayBased::isEmpty()
{
    if (m_valuesother[0] = 0)
        return true;
    else
        return false;
}

bool ArrayBased::insert(int val)
{
    int size = 5000;
   /* for (int i : m_valuesother)
    {
        
            size++;
    }*/
    /*for (int i = 0; i < size; i++)
    {
        if (m_valuesother[i] == 0)
        {
            m_valuesother[i] = val;
        }
        break;
    }*/


    int idk = 0;
    int count = 0;
    for  (int i = 0; i < size; i++){
        if (m_valuesother[i] == 0 && idk == 0){
            m_valuesother[i] = val;
            idk = 1;
            break;
        }
        count++;
    }
    othersort();
    return true;
    
}

bool ArrayBased::DeQueue()
{
    
    int size = 0;
    for (int i : m_valuesother)
    {
        if (i != 0)
            size++;
    }

    m_valuesother[0] = 0;
    othersort();
    return true;
    
}

std::string ArrayBased::toString() const
{
    std::string queue;
    for (int i : m_valuesother)
    {
        if (i != 0)
            queue = queue + " " + to_string(i);
    }
    return queue;
}

