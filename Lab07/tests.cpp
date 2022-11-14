#include "priorityQueue.h"
#include <gtest/gtest.h>

TEST(arrayBased, insert1)
{
    ArrayBased pq = ArrayBased();
    pq.insert(2);
    ASSERT_FALSE(pq.isEmpty());
}
TEST(arrayBased, insert2)
{
    ArrayBased pq = ArrayBased();
    pq.insert(5);
    pq.insert(2);
    ASSERT_FALSE(pq.isEmpty());
}
TEST(arrayBased, dequeue1)
{
    ArrayBased pq = ArrayBased();
    pq.insert(2);
    pq.DeQueue();
    ASSERT_TRUE(!pq.isEmpty());
}
TEST(arrayBased, dequeue2)
{
    ArrayBased pq = ArrayBased();
    pq.insert(2);
    pq.insert(3);
    pq.DeQueue();
    ASSERT_FALSE(pq.isEmpty());
}
TEST(arrayBased, tostring1)
{
    ArrayBased pq = ArrayBased();
    pq.insert(2);
    pq.insert(3);
    ASSERT_EQ(pq.toString()," 3 2");
}
TEST(arrayBased, tostring2)
{
    ArrayBased pq = ArrayBased();
    pq.insert(2);
    ASSERT_EQ(pq.toString()," 2");
}
TEST(heap, insert1)
{
    HeapBased pq = HeapBased();
    pq.insert(2);
    ASSERT_FALSE(pq.isEmpty());
}
TEST(heap, insert2)
{
    HeapBased pq = HeapBased();
    pq.insert(5);
    pq.insert(2);
    ASSERT_FALSE(pq.isEmpty());
}
TEST(heap, dequeue1)
{
    HeapBased pq = HeapBased();
    pq.insert(2);
    pq.DeQueue();
    ASSERT_TRUE(!pq.isEmpty());
}
TEST(heap, dequeue2)
{
    HeapBased pq = HeapBased();
    pq.insert(2);
    pq.insert(3);
    pq.DeQueue();
    ASSERT_FALSE(pq.isEmpty());
}
TEST(heap, tostring1)
{
    HeapBased pq = HeapBased();
    pq.insert(2);
    pq.insert(3);
    ASSERT_EQ(pq.toString()," 3 2");
}
TEST(heap, tostring2)
{
    HeapBased pq = HeapBased();
    pq.insert(2);
    ASSERT_EQ(pq.toString()," 2");
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}