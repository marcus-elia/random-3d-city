#ifndef RANDOM_3D_CITY_TRIPRISM_H
#define RANDOM_3D_CITY_TRIPRISM_H

#include "solid.h"
#include "movableObject.h"

// This makes an isosceles triangular prism whose
// base is facing down

class TriPrism : public Solid, public MovableObject
{
public:
    TriPrism();
    TriPrism(Point inputCenter, RGBAcolor inputColor,
             double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor);

    void initializeCorners();

    void move(double deltaX, double deltaY, double deltaZ);

    void rotate(double thetaX, double thetaY, double thetaZ);

    void lookAt(Point &p);

    void draw() const;
    void drawLines() const;
    void drawFaces() const;

    std::experimental::optional<Point> correctCollision(Point p, int buffer);

    void printDebugStats();
};


#endif //RANDOM_3D_CITY_TRIPRISM_H
