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
};

#endif //RANDOM_3D_CITY_RECPRISM_H
