// Sqaure.h
//
//

#pragma once

#include "Shape.h"

class Square : public Shape
{
public:

   Square(double sideLength);

   ~Square();

   double getArea();

   double getPerimeter();

};

