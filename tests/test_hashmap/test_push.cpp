#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(PushTest, InsertOneElement)
{
    HashMap<int,int> map;
    map.push(1,100);

    EXPECT_NE(map.find(1), nullptr);
    EXPECT_EQ(map.find(1)->Value,100);
}

TEST(PushTest, InsertMultipleElements)
{
    HashMap<int,int> map;

    map.push(1,10);
    map.push(2,20);
    map.push(3,30);

    EXPECT_EQ(map.find(1)->Value,10); 
    EXPECT_EQ(map.find(2)->Value,20);
    EXPECT_EQ(map.find(3)->Value,30);
}

TEST(PushTest, UpdateExistingKey)
{
    HashMap<int,int> map;

    map.push(5,10);
    map.push(5,100);

    EXPECT_EQ(map.find(5)->Value,100);
}

TEST(PushTest, InsertNegativeKey)
{
    HashMap<int,int> map;

    map.push(-1,50);

    EXPECT_EQ(map.find(-1)->Value,50);
}

TEST(PushTest, RehashInsertion)
{
    HashMap<int,int> map;

    for(int i=0;i<100;i++)
        map.push(i,i*10);

    EXPECT_EQ(map.find(99)->Value,990);
}