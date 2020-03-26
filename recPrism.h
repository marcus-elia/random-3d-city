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

    void draw() const;
    void drawLines() const;
    void drawFaces() const;
};

#endif //RANDOM_3D_CITY_RECPRISM_H
