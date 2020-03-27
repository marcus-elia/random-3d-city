#include "chunk.h"

Chunk::Chunk()
{
    bottomLeft = {0,0};
    sideLength = 1024;
    initializeCenter();
}
Chunk::Chunk(Point2D inputBottomLeft, int inputSideLength)
{
    bottomLeft = inputBottomLeft;
    sideLength = inputSideLength;
    initializeCenter();
}

void Chunk::initializeCenter()
{
    center = {bottomLeft.x + sideLength/2, bottomLeft.z - sideLength/2};
}

// Getters
Point2D Chunk::getBottomLeft() const
{
    return bottomLeft;
}
int Chunk::getSideLength() const
{
    return sideLength;
}
Point2D Chunk::getCenter() const
{
    return center;
}

void Chunk::draw() const
{
    glBegin(GL_QUADS);
    glColor4f(1, 1, 0.3, 1);
    glVertex2f(bottomLeft.x, bottomLeft.z);
    glVertex2f(bottomLeft.x + sideLength, bottomLeft.z);
    glVertex2f(bottomLeft.x + sideLength, bottomLeft.z + sideLength);
    glVertex2f(bottomLeft.x, bottomLeft.z + sideLength);
    glEnd();
}

int pointToInt(Point2D p)
{
    int a = p.x;
    int b = p.z;
    if(a > 0 && b <= a-1 && b > -a)
    {
        return 4*a*a - 3*a - b;
    }
    else if(b < 0 && a <= -b && a > b+1)
    {
        return 4*b*b + b - a;
    }
    else if(a < 0 && b >= a-1 && b < -a)
    {
        return 4*a*a - a + b;
    }
    else if(b > -1 && a >= -b && a < b+1)
    {
        return 4*b*b + 3*b + a;
    }
    return 3; // idk why, but (0,-1) -> 3 is the only special case

}