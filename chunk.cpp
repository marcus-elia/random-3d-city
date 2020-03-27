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