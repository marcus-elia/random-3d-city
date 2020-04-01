#include "triPrism.h"

TriPrism::TriPrism() : Solid(), MovableObject()
{
    initializeCorners();
}
TriPrism::TriPrism(Point inputCenter, RGBAcolor inputColor,
                   double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor) :
        Solid(inputCenter, inputColor, inputXWidth, inputYWidth, inputZWidth, inputLineColor),
        MovableObject()
{
    initializeCorners();
}

void TriPrism::initializeCorners()
{
    corners.push_back({center.x + xWidth/2, center.y - yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x - xWidth/2, center.y - yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x, center.y + yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x + xWidth/2, center.y - yWidth/2, center.z - zWidth/2});
    corners.push_back({center.x - xWidth/2, center.y - yWidth/2, center.z - zWidth/2});
    corners.push_back({center.x, center.y + yWidth/2, center.z - zWidth/2});
}


void TriPrism::move(double deltaX, double deltaY, double deltaZ)
{

}

void TriPrism::rotate(double thetaX, double thetaY, double thetaZ)
{

}

void TriPrism::lookAt(Point &p)
{

}

void TriPrism::draw() const
{
    drawLines();
    drawFaces();
}

void TriPrism::drawLines() const
{
    glColor4f(lineColor.r, lineColor.g, lineColor.b, lineColor.a);
    glBegin(GL_LINES);
    drawPoint(corners[1]);
    drawPoint(corners[0]);

    drawPoint(corners[1]);
    drawPoint(corners[2]);

    drawPoint(corners[2]);
    drawPoint(corners[0]);

    drawPoint(corners[1]);
    drawPoint(corners[4]);

    drawPoint(corners[2]);
    drawPoint(corners[5]);

    drawPoint(corners[0]);
    drawPoint(corners[3]);

    drawPoint(corners[3]);
    drawPoint(corners[4]);

    drawPoint(corners[4]);
    drawPoint(corners[5]);

    drawPoint(corners[5]);
    drawPoint(corners[3]);

    glEnd();
}

void TriPrism::drawFaces() const
{

    glColor4f(color.r, color.g, color.b, color.a);

    glBegin(GL_TRIANGLES);

    drawPoint(corners[0]);
    drawPoint(corners[1]);
    drawPoint(corners[2]);

    drawPoint(corners[3]);
    drawPoint(corners[5]);
    drawPoint(corners[4]);

    glEnd();

    glBegin(GL_QUADS);

    drawPoint(corners[2]);
    drawPoint(corners[1]);
    drawPoint(corners[4]);
    drawPoint(corners[5]);
    
    drawPoint(corners[5]);
    drawPoint(corners[3]);
    drawPoint(corners[0]);
    drawPoint(corners[2]);

    drawPoint(corners[1]);
    drawPoint(corners[0]);
    drawPoint(corners[3]);
    drawPoint(corners[4]);

    glEnd();
}