// A solid is an abstract class that will be extended by
// prisms, pyramids, spheres
#ifndef RANDOM_3D_CITY_SOLID_H
#define RANDOM_3D_CITY_SOLID_H

#include "drawableObject.h"
#include <vector>
#include <experimental/optional>

class Solid : public DrawableObject
{
protected:
    std::vector<Point> corners;
    double xWidth;
    double yWidth;
    double zWidth;
    RGBAcolor lineColor;
public:
    // Constructors
    Solid();
    Solid(Point inputCenter, RGBAcolor inputColor,
            double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor);

    // Initialization
    virtual void initializeCorners();

    // Getters
    std::vector<Point> getCorners() const;
    double getXWidth() const;
    double getYWidth() const;
    double getZWidth() const;
    RGBAcolor getLineColor() const;

    // Setter
    void setCorners(std::vector<Point> inputCorners);
    void setXWidth(double inputXWidth);
    void setYWidth(double inputYWidth);
    void setZWidth(double inputZWidth);
    void setLineColor(RGBAcolor inputLineColor);

    // If the p is within buffer of this shape, a corrected position
    // is returned. returns nullopt otherwise.
    virtual std::experimental::optional<Point> correctCollision(Point p, int buffer);
};

#endif //RANDOM_3D_CITY_SOLID_H
