// Triangle.cpp
//
//
#include <cmath>

#include "Triangle.h"

Triangle::Triangle(double edgeLength)
 : Shape(edgeLength)
{}

Triangle::~Triangle()
{}

double Triangle::getArea()
{
   return (sqrt(3.0) / 4.0) * sideLength * sideLength ;
}

double Triangle::getPerimeter()
{
   return 3.0 * sideLength;
}
