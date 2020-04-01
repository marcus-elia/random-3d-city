#include "recPrism.h"

RecPrism::RecPrism() : Solid(), MovableObject()
{
    initializeCorners();
}
RecPrism::RecPrism(Point inputCenter, RGBAcolor inputColor,
        double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor) :
        Solid(inputCenter, inputColor, inputXWidth, inputYWidth, inputZWidth, inputLineColor),
        MovableObject()
{
    initializeCorners();
}

void RecPrism::initializeCorners()
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


void RecPrism::move(double deltaX, double deltaY, double deltaZ)
{

}

void RecPrism::rotate(double thetaX, double thetaY, double thetaZ)
{

}

void RecPrism::lookAt(Point &p)
{

}

void RecPrism::draw() const
{
    drawLines();
    drawFaces();
}

void RecPrism::drawLines() const
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

void RecPrism::drawFaces() const
{
    glBegin(GL_QUADS);
    glColor4f(color.r, color.g, color.b, color.a);

    drawPoint(corners[0]);
    drawPoint(corners[1]);
    drawPoint(corners[3]);
    drawPoint(corners[2]);

    drawPoint(corners[5]);
    drawPoint(corners[4]);
    drawPoint(corners[6]);
    drawPoint(corners[7]);

    drawPoint(corners[6]);
    drawPoint(corners[4]);
    drawPoint(corners[0]);
    drawPoint(corners[2]);

    drawPoint(corners[4]);
    drawPoint(corners[5]);
    drawPoint(corners[1]);
    drawPoint(corners[0]);

    drawPoint(corners[6]);
    drawPoint(corners[2]);
    drawPoint(corners[3]);
    drawPoint(corners[7]);

    drawPoint(corners[3]);
    drawPoint(corners[1]);
    drawPoint(corners[5]);
    drawPoint(corners[7]);
    glEnd();
}

std::experimental::optional<Point> RecPrism::correctCollision(Point p, int buffer)
{
    // If it is ouside the prism, just return nullopt
    if(p.x < center.x - xWidth/2 - buffer || p.x > center.x + xWidth/2 + buffer ||
       p.z < center.z - zWidth/2 - buffer || p.z > center.z + zWidth/2 + buffer ||
       p.y > center.y + yWidth/2 + buffer)
    {
        return std::experimental::nullopt;
    }
    // If we're close to the left side
    if(abs(p.x - center.x + xWidth/2) < buffer)
    {
        return std::experimental::optional<Point>({center.x - xWidth/2 - buffer, p.y, p.z});
    }
    // Right side
    else if(abs(p.x - center.x - xWidth/2) < buffer)
    {
        return std::experimental::optional<Point>({center.x + xWidth/2 + buffer, p.y, p.z});
    }
    // Back side
    else if(abs(p.z - center.z + zWidth/2) < buffer)
    {
        return std::experimental::optional<Point>({p.x, p.y, center.z - zWidth/2 - buffer});
    }
    // Front side
    else if(abs(p.z - center.z - zWidth/2) < buffer)
    {
        return std::experimental::optional<Point>({p.x, p.y, center.z + zWidth/2 + buffer});
    }
    // Assume bottom or top
    else if(abs(p.y - center.y + yWidth/2) < buffer)
    {
        return std::experimental::optional<Point>({p.x, center.y - yWidth/2 - buffer, p.z});
    }
    else
    {
        return std::experimental::optional<Point>({p.x, center.y + yWidth/2 + buffer, p.z});
    }
}