#ifndef RANDOM_3D_CITY_RECPRISM_H
#define RANDOM_3D_CITY_RECPRISM_H

#include "solid.h"
#include "movableObject.h"

class RecPrism : public Solid, public MovableObject
{
public:
    RecPrism();
    RecPrism(Point inputCenter, RGBAcolor inputColor,
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

std::experimental::optional<Point> correctRectangularPrismCollision(Point p, int buffer, Point c,
        double xw, double yw, double zw);

#endif //RANDOM_3D_CITY_RECPRISM_H
