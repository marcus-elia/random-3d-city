#ifndef RANDOM_3D_CITY_TESTING_CPP
#define RANDOM_3D_CITY_TESTING_CPP

#include <iostream>
#include <cmath>
#include "chunk.h"
#include "perlinNoiseGenerator.h"
#include "recPrism.h"

#endif //RANDOM_3D_CITY_TESTING_CPP

void testPointToInt();
void testGetChunksAroundPoint();
void testPerlinNoiseGenerator();
void testCorrectRectangularPrismCollision();

int main()
{
    testPointToInt();
    testGetChunksAroundPoint();
    testPerlinNoiseGenerator();
    testCorrectRectangularPrismCollision();
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

void testPerlinNoiseGenerator()
{
    std::cout << std::endl << "Testing PerlinNoiseGenerator()" << std::endl;
    PerlinNoiseGenerator png = PerlinNoiseGenerator(10, 10, 1);
    std::vector<std::vector<double>> noise = png.getPerlinNoise();
    for(std::vector<double> vec : noise)
    {
        for(double d : vec)
        {
            std::cout << d << ", ";
        }
        std::cout << std::endl;
    }
}

void testCorrectRectangularPrismCollision()
{
    std::cout << std::endl << "Testing CorrectRectangularPrismCollision()" << std::endl;

    bool passed = true;
    Point p,c;
    int buffer;
    double xw, yw, zw;
    Point obs, exp;

    c = {0, 50, 0};
    xw = 20;
    yw = 100;
    zw = 20;
    buffer = 1;

    // Points on Faces
    // On front side
    p = {0, 50, 10};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 50, 11};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point on front face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
        << obs.x << "," << obs.y << "," << obs.z << std::endl;
        //std::cout << "Expected " << exp << ", observed " << obs << std::endl;
    }
    // On left side
    p = {-10, 50, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {-11, 50, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point on left face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // On back side
    p = {0, 50, -10};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 50, -11};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point on back face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // On right side
    p = {10, 50, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {11, 50, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point on right face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // On top side
    p = {0, 100, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 101, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point on top face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // On bottom side
    p = {0, -1, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, -1, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point on bottom face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }

    // Points inside Prism
    // Close to front side
    p = {0, 50, 8};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 50, 11};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point inside front face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
        //std::cout << "Expected " << exp << ", observed " << obs << std::endl;
    }
    // In left side
    p = {-8, 50, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {-11, 50, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point in left face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // In back side
    p = {0, 50, -8};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 50, -11};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point in back face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // In right side
    p = {8, 50, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {11, 50, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point in right face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // in top side
    p = {0, 95, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 101, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point in top face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // in bottom side
    p = {0, 5, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, -1, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point in bottom face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }

    buffer = 5;
    // Points outside
    // Near front side
    p = {0, 50, 12};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 50, 15};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point near front face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // Near left side
    p = {-12, 50, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {-15, 50, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point near left face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // Near back side
    p = {0, 50, -12};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 50, -15};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point near back face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // Near right side
    p = {12, 50, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {15, 50, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point near right face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // Near top side
    p = {0, 102, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, 105, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point near top face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }
    // Near bottom side
    p = {0, -2, 0};
    obs = correctRectangularPrismCollision(p, buffer, c, xw, yw, zw).value_or(Point({500,500,500}));
    exp = {0, -5, 0};
    if(distanceFormula(obs, exp) > 1)
    {
        passed = false;
        std::cout << "Test FAILED for point near bottom face" << std::endl;
        std::cout << "Expected " << exp.x << "," << exp.y << "," << exp.z << ", observed "
                  << obs.x << "," << obs.y << "," << obs.z << std::endl;
    }

    if(passed)
    {
        std::cout << "All tests passed." << std::endl;
    }
}
