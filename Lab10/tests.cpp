
#include <gtest/gtest.h>
#include "hashTable.h"
#include <vector>
#include <iostream>

TEST(hashTests, add1)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    int s = t->getItem(1);
    ASSERT_EQ(1,s);
}
TEST(hashTests, add2)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    int s = t->getItem(2);
    ASSERT_EQ(2,s);
}
TEST(hashTests, getItem1)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    int s = t->getItem(2);
    ASSERT_EQ(2,s);
}
TEST(hashTests, getItem2)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    int s = t->getItem(1);
    ASSERT_EQ(1,s);
}
TEST(hashTests, contains1)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    int s = t->contains();
    ASSERT_EQ(2,s);
}
TEST(hashTests, contains2)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    t->add(3,3);
    t->add(4,4);
    t->add(5,5);
    t->add(6,6);
    t->add(10,7);
    int s = t->contains();
    ASSERT_EQ(7,s);
}
TEST(hashTests, hash1)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    t->add(3,3);
    t->add(4,4);
    t->add(5,5);
    t->add(6,6);
    t->add(7,7);
    int h = t->hash(4);
    ASSERT_EQ(4,h);
}
TEST(hashTests, hash2)
{
    hashTable<int, int>* t = new hashTable<int, int>(10);
    t->add(1,1);
    t->add(2,2);
    t->add(3,3);
    t->add(4,4);
    t->add(5,5);
    t->add(6,6);
    t->add(7,7);
    int h = t->hash(7);
    ASSERT_EQ(7,h);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}