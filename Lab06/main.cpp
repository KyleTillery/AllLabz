#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include "BST.h"
#include "Node.h"


using namespace std;
int main()
{

    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(8);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(6);
    std::shared_ptr<Node<int>> item3 = std::make_shared<Node<int>>(7);
    std::shared_ptr<Node<int>> item4 = std::make_shared<Node<int>>(12);
    std::shared_ptr<Node<int>> item5 = std::make_shared<Node<int>>(13);
    myBST.insert(item1);
    myBST.insert(item2);
    myBST.insert(item3);
    myBST.insert(item4);
    myBST.insert(item5);
    std::shared_ptr<Node<int>> found = myBST.find(7);
    cout << found->getItem() << endl;
    cout<< to_string(myBST.size());
    cout<<endl;
    stack<int> gas = myBST.GetAllAscending();
    while (!gas.empty())
    {
        int i = gas.top();
        cout << i << " ";
        gas.pop();
    }
    cout <<endl;
    myBST.clearTree();
    cout << to_string(myBST.size()) << endl;
    


    return 0;
}