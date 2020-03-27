#include <iostream>
#include <cmath>
#include "chunk.h"

void testPointToInt();

int main()
{
    testPointToInt();
    return 0;
}

void testPointToInt()
{
    std::cout << std::endl << "Testing PointToInt()" << std::endl;

    bool passed = true;
    std::vector<Point2D> values;
    std::vector<int> expected;

    // Make a bunch of tests
    values.push_back({0,0});
    expected.push_back(0);
    values.push_back({1,0});
    expected.push_back(1);
    values.push_back({1,-1});
    expected.push_back(2);
    values.push_back({0,-1});
    expected.push_back(3);
    values.push_back({-1,-1});
    expected.push_back(4);
    values.push_back({-1,0});
    expected.push_back(5);
    values.push_back({-1,1});
    expected.push_back(6);
    values.push_back({0,1});
    expected.push_back(7);
    values.push_back({1,1});
    expected.push_back(8);
    values.push_back({2,1});
    expected.push_back(9);
    values.push_back({2,0});
    expected.push_back(10);
    values.push_back({2,-1});
    expected.push_back(11);
    values.push_back({2,-2});
    expected.push_back(12);
    values.push_back({4,3});
    expected.push_back(49);

    for(int i = 0; i < values.size(); i++)
    {
        int observed = pointToInt(values[i]);
        if(observed != expected[i])
        {
            passed = false;
            std::cout << "Test FAILED" << std::endl;
            std::cout << "Expected " << expected[i] << ", observed " << observed << std::endl;
        }
    }
    if(passed)
    {
        std::cout << "All tests passed." << std::endl;
    }
}
