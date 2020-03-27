#ifndef RANDOM_3D_CITY_CHUNK_H
#define RANDOM_3D_CITY_CHUNK_H

#include "graphics.h"

// int points used for the chunks
// in the xz plane
struct Point2D
{
    int x;
    int z;
};


class Chunk
{
private:
    Point2D bottomLeft;
    int sideLength;
    Point2D center;
private:
    Chunk();
    Chunk(Point2D inputBottomLeft, int inputSideLength);

    void initializeCenter();

    // Getters
    Point2D getBottomLeft() const;
    int getSideLength() const;
    Point2D getCenter() const;

    void draw() const;
};

#endif //RANDOM_3D_CITY_CHUNK_H
