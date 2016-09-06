// Octagon.h
//
//

#pragma once

#include "Shape.h"

class Octagon : public Shape
{
public:

   Octagon(double sideLength);

   ~Octagon();

   double getArea();

   double getPerimeter();

};
