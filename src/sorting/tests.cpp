#include <gtest/gtest.h>

#include <vector>
#include <iostream>
#include <random>

TEST(SortingTest, FixedInput)
{
    std::vector<int> input{5, 4, 10, 8, 1, -5, 99};
    int before = input.front();
    for (auto current = input.begin(); current != input.end(); ++current)
    {
        EXPECT_GE(*current, before) << "Failed at index: " << std::distance(input.begin(), current);
    }
}

TEST(SortingTest, RandomInput)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max());

    std::vector<int> input(1000, 0);
    std::generate(input.begin(), input.end(), [&rng, &dist]() {return dist(rng); });

    ASSERT_GT(input.size(), 1);
    int before = input.front();
    for (auto current = input.begin(); current != input.end(); ++current)
    {
        EXPECT_GE(*current, before) << "Failed at index: " << std::distance(input.begin(), current);
    }
}