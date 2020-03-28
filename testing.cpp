#include <iostream>
#include <cmath>
#include "chunk.h"

void testPointToInt();
void testGetChunksAroundPoint();

int main()
{
    testPointToInt();
    testGetChunksAroundPoint();
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
    values.push_back({1,-2});
    expected.push_back(13);
    values.push_back({0,-2});
    expected.push_back(14);
    values.push_back({-1,-2});
    expected.push_back(15);
    values.push_back({-2,-2});
    expected.push_back(16);
    values.push_back({-2,-1});
    expected.push_back(17);
    values.push_back({-2,-3});
    expected.push_back(35);
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

void testGetChunksAroundPoint()
{
    std::cout << std::endl << "Testing GetChunksAroundPoint()" << std::endl;

    bool passed = true;

    Point2D p;
    int radius;
    std::vector<int> expected;
    std::vector<int> observed;

    p = {0,0};
    radius = 0;
    expected = std::vector<int>({0});
    observed = getChunksAroundPoint(p, radius);
    if(expected != observed)
    {
        passed = false;
        std::cout << "Test FAILED for p = " << p.x << "," << p.z << " and r = " << radius << std::endl;
    }
    p = {0,0};
    radius = 1;
    expected = std::vector<int>({7,5,0,1,3});
    observed = getChunksAroundPoint(p, radius);
    if(expected != observed)
    {
        passed = false;
        std::cout << "Test FAILED for p = " << p.x << "," << p.z << " and r = " << radius << std::endl;
    }
    p = {0,0};
    radius = 2;
    expected = std::vector<int>({22,6,7,8,18,5,0,1,10,4,3,2,14});
    observed = getChunksAroundPoint(p, radius);
    if(expected != observed)
    {
        passed = false;
        std::cout << "Test FAILED for p = " << p.x << "," << p.z << " and r = " << radius << std::endl;
    }
    p = {-1,-1};
    radius = 1;
    expected = std::vector<int>({5,17,4,3,15});
    observed = getChunksAroundPoint(p, radius);
    if(expected != observed)
    {
        passed = false;
        std::cout << "Test FAILED for p = " << p.x << "," << p.z << " and r = " << radius << std::endl;
    }

    if(passed)
    {
        std::cout << "All tests passed." << std::endl;
    }
}
