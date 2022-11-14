#include <gtest/gtest.h>
#include "BST.h"



TEST(BSTTESTS, insert1)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);

    myBST.insert(item1);
    std::shared_ptr<Node<int>> found = myBST.find(3); 
    
    ASSERT_EQ(found->getItem(), 3);
}
TEST(BSTTESTS, insert2)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    myBST.insert(item1);
    myBST.insert(item2);
    std::shared_ptr<Node<int>> found = myBST.find(4); 
    
    ASSERT_EQ(found->getItem(), 4);

}
TEST(BSTTESTS, find1)
{
   BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    myBST.insert(item1);
    myBST.insert(item2);
    std::shared_ptr<Node<int>> found = myBST.find(4);
    ASSERT_EQ(found->getItem(), 4);

}
TEST(BSTTESTS, find2)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    myBST.insert(item1);
    myBST.insert(item2);
    std::shared_ptr<Node<int>> found = myBST.find(3); 
    ASSERT_EQ(found->getItem(), 3);

}
TEST(BSTTESTS, size1)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    myBST.insert(item1);
    myBST.insert(item2);
    int a = myBST.size();
    ASSERT_EQ(a, 2);

}
TEST(BSTTESTS, size2)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    myBST.insert(item1);
    int a = myBST.size(); 
    ASSERT_EQ(a, 1);

}
TEST(BSTTESTS, GetAllAscending1)
{
   BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    std::shared_ptr<Node<int>> item3 = std::make_shared<Node<int>>(1);
    std::shared_ptr<Node<int>> item4 = std::make_shared<Node<int>>(10);
    std::shared_ptr<Node<int>> item5 = std::make_shared<Node<int>>(5);
    myBST.insert(item1);
    myBST.insert(item2);
    myBST.insert(item3);
    myBST.insert(item4);
    myBST.insert(item5);
    std::stack<int> gas = myBST.GetAllAscending();
    std::stack<int> check = gas;
    ASSERT_EQ(check, gas);   

}
TEST(BSTTESTS, GetAllAscending2)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    std::shared_ptr<Node<int>> item3 = std::make_shared<Node<int>>(1);
    std::shared_ptr<Node<int>> item4 = std::make_shared<Node<int>>(10);
    std::shared_ptr<Node<int>> item5 = std::make_shared<Node<int>>(5);
    std::shared_ptr<Node<int>> item6 = std::make_shared<Node<int>>(100);
    myBST.insert(item1);
    myBST.insert(item2);
    myBST.insert(item3);
    myBST.insert(item4);
    myBST.insert(item5);
    myBST.insert(item6);
    std::stack<int> gas = myBST.GetAllAscending();
    std::stack<int> check = gas;
    
    ASSERT_EQ(check, gas);

}
TEST(BSTTESTS, clear1)
{
    BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    std::shared_ptr<Node<int>> item3 = std::make_shared<Node<int>>(1);
    std::shared_ptr<Node<int>> item4 = std::make_shared<Node<int>>(10);
    std::shared_ptr<Node<int>> item5 = std::make_shared<Node<int>>(5);
    std::shared_ptr<Node<int>> item6 = std::make_shared<Node<int>>(100);
    myBST.insert(item1);
    myBST.insert(item2);
    myBST.insert(item3);
    myBST.insert(item4);
    myBST.insert(item5);
    myBST.insert(item6);
    myBST.clearTree();
    int size = myBST.size();
    ASSERT_EQ(size, 0);

}
TEST(BSTTESTS, clear2)
{
   BST<int> myBST;

    std::shared_ptr<Node<int>> item1 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> item2 = std::make_shared<Node<int>>(4);
    myBST.insert(item1);
    myBST.clearTree(); 
    int size = myBST.size();
    ASSERT_EQ(size, 0); 

}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}