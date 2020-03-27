#ifndef RANDOM_3D_CITY_CHUNK_H
#define RANDOM_3D_CITY_CHUNK_H

#include "graphics.h"
#include <vector>

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

    // The number of the chunk based on its location
    int chunkID;
private:
    Chunk();
    Chunk(Point2D inputBottomLeft, int inputSideLength);

    void initializeCenter();

    // Getters
    Point2D getBottomLeft() const;
    int getSideLength() const;
    Point2D getCenter() const;

    void draw() const;

    // Chunk things
    std::vector<int> getChunksAround(int radius);
};

// Returns the result of mapping a 2d point in Z x Z into the
// non-negative integers, by spiraling clockwise.
int pointToInt(Point2D p);

#endif //RANDOM_3D_CITY_CHUNK_H
