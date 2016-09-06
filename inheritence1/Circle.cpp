// Circle.cpp
//
//

#include <cmath>

#include "Circle.h"

Circle::Circle(double radius)
 : Shape(radius)
{}

Circle::~Circle()
{}

double Circle::getArea()
{
   return M_PI * sideLength * sideLength;
}

double Circle::getPerimeter()
{
   return 2.0 * M_PI * sideLength;
}

