// Circle.h
//
//

#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:

   Circle(double radius);

   ~Circle();

   double getArea();

   double getPerimeter();

};


