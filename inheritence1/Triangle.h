// Triangle.h
//
//

#pragma once

#include "Shape.h"

class Triangle : public Shape
{
public:

   Triangle(double edgeLength);

   ~Triangle();

   double getArea();

   double getPerimeter();

};
