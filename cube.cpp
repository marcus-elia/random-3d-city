#include "cube.h"

Cube::Cube()
{
    center = {0, 100, 0};
    sideLength = 10;
    xWidth = 10;
    yWidth = 10;
    zWidth = 10;
    color = {1,1,1,1};
    lineColor = {1,1,1,1};
    rotationSpeed = {1,1,1};
}
Cube::Cube(Point inputCenter, RGBAcolor inputColor, double inputSideLength, RGBAcolor inputLineColor,
Point inputRotationSpeed) :
RecPrism(inputCenter, inputColor, inputSideLength, inputSideLength, inputSideLength, inputLineColor)
{
    sideLength = inputSideLength;
    rotationSpeed = inputRotationSpeed;
}

void Cube::initializeCorners()
{
    corners.push_back({center.x + xWidth/2, center.y + yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x - xWidth/2, center.y + yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x + xWidth/2, center.y - yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x - xWidth/2, center.y - yWidth/2, center.z + zWidth/2});
    corners.push_back({center.x + xWidth/2, center.y + yWidth/2, center.z - zWidth/2});
    corners.push_back({center.x - xWidth/2, center.y + yWidth/2, center.z - zWidth/2});
    corners.push_back({center.x + xWidth/2, center.y - yWidth/2, center.z - zWidth/2});
    corners.push_back({center.x - xWidth/2, center.y - yWidth/2, center.z - zWidth/2});
}

void Cube::move(double deltaX, double deltaY, double deltaZ)
{
    center.x += deltaX;
    center.y += deltaY;
    center.z += deltaZ;
    for (Point &p : corners)
    {
        p.x += deltaX;
        p.y += deltaY;
        p.z += deltaZ;
    }
}

void Cube::rotate(double thetaX, double thetaY, double thetaZ)
{
    for (Point &p : corners)
    {
        rotatePointAroundPoint(p, center, thetaX, thetaY, thetaZ);
    }
}
void Cube::rotateSelf()
{
    rotate(rotationSpeed.x, rotationSpeed.y, rotationSpeed.z);
}

void Cube::lookAt(Point &p)
{

}

void Cube::draw() const
{
    drawLines();
}
void Cube::drawLines() const
{
    glColor4f(lineColor.r, lineColor.g, lineColor.b, lineColor.a);
    glBegin(GL_LINES);
    drawPoint(corners[1]);
    drawPoint(corners[0]);

    drawPoint(corners[1]);
    drawPoint(corners[3]);

    drawPoint(corners[3]);
    drawPoint(corners[2]);

    drawPoint(corners[2]);
    drawPoint(corners[0]);

    drawPoint(corners[4]);
    drawPoint(corners[5]);

    drawPoint(corners[5]);
    drawPoint(corners[7]);

    drawPoint(corners[7]);
    drawPoint(corners[6]);

    drawPoint(corners[6]);
    drawPoint(corners[4]);

    drawPoint(corners[0]);
    drawPoint(corners[4]);

    drawPoint(corners[2]);
    drawPoint(corners[6]);

    drawPoint(corners[3]);
    drawPoint(corners[7]);

    drawPoint(corners[1]);
    drawPoint(corners[5]);

    glEnd();
}

void rotatePointAroundPoint(Point &p, const Point &pBase, double thetaX, double thetaY, double thetaZ)
{
    // Store the previous coordinates during calculations
    double prevX = 0, prevY = 0, prevZ = 0;

    // Translate pBase to the origin by moving p
    p.x -= pBase.x;
    p.y -= pBase.y;
    p.z -= pBase.z;

    // Rotate around x-axis
    prevY = p.y;
    prevZ = p.z;
    p.y = prevY * cos(thetaX) - prevZ * sin(thetaX);
    p.z = prevY * sin(thetaX) + prevZ * cos(thetaX);

    // Rotate around y-axis
    prevX = p.x;
    prevZ = p.z;
    p.x = prevX * cos(thetaY) - prevZ * sin(thetaY);
    p.z = prevX * sin(thetaY) + prevZ * cos(thetaY);

    // Rotate around z-axis
    prevX = p.x;
    prevY = p.y;
    p.x = prevX * cos(thetaZ) - prevY * sin(thetaZ);
    p.y = prevX * sin(thetaZ) + prevY * cos(thetaZ);

    // Translate back
    p.x += pBase.x;
    p.y += pBase.y;
    p.z += pBase.z;
}