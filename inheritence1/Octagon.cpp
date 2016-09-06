// Octagon.cpp
//
//
#include <cmath>

#include "Octagon.h"

Octagon::Octagon(double s)
 : Shape(s)
{}

Octagon::~Octagon()
{}

double Octagon::getArea()
{
   return 2 * (1 + sqrt(2)) *  sideLength * sideLength;
}

double Octagon::getPerimeter()
{
   return 8.0 * sideLength;
}

