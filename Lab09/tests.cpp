// tests.cpp

#include <gtest/gtest.h>
#include "graph.h"
#include <vector>
#include <iostream>

TEST(graphTests, construct1)
{
    graph newGraph(5);
    
    ASSERT_TRUE(true); // if the code hits this we can assume that the object has been created and no error has been made
}
TEST(graphTests, construct2)
{
    graph newGraph(10);
    
    ASSERT_TRUE(true); // if the code hits this we can assume that the object has been created and no error has been made
}	
TEST(graphTests, addEdge1)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    ASSERT_TRUE(newGraph.hasEdge(0,0));
}
TEST(graphTests, addEdge2)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    ASSERT_FALSE(newGraph.hasEdge(2,3));
}
TEST(graphTests, removeEdge1)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.removeEdge(0,0);
    ASSERT_FALSE(newGraph.hasEdge(0,0));
}
TEST(graphTests, removeEdge2)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.removeEdge(0,1);
    ASSERT_TRUE(newGraph.hasEdge(0,0));
}
TEST(graphTests, hasEdge1)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    ASSERT_TRUE(newGraph.hasEdge(0,0));
}
TEST(graphTests, hasEdge2)
{
    graph newGraph(5);
    newGraph.addEdge(3,3);
    ASSERT_TRUE(newGraph.hasEdge(3,3));
}
TEST(graphTests, outEdge1)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.addEdge(1,1);
    newGraph.addEdge(0,1);
    newGraph.addEdge(2,3);
    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    ASSERT_EQ(newGraph.outEdges(),a);

}
TEST(graphTests, outEdge2)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.addEdge(1,4);
    newGraph.addEdge(3,2);
    newGraph.addEdge(2,1);
    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    ASSERT_EQ(newGraph.outEdges(),a);
}
TEST(graphTests, inEdge1)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.addEdge(1,1);
    newGraph.addEdge(0,1);
    newGraph.addEdge(2,3);
    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    ASSERT_EQ(newGraph.outEdges(),a);
}
TEST(graphTests, inEdge2)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.addEdge(1,4);
    newGraph.addEdge(4,2);
    newGraph.addEdge(2,1);
    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    ASSERT_EQ(newGraph.outEdges(),a);
}
TEST(graphTests, printEdge1)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.addEdge(1,1);
    newGraph.addEdge(0,1);
    newGraph.addEdge(2,3);
    ASSERT_TRUE(newGraph.PrintOutMatrix());
}
TEST(graphTests, printEdge2)
{
    graph newGraph(5);
    newGraph.addEdge(0,0);
    newGraph.addEdge(1,4);
    newGraph.addEdge(0,2);
    newGraph.addEdge(2,1);
    ASSERT_TRUE(newGraph.PrintOutMatrix());
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
