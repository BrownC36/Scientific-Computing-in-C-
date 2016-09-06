// Shape.h
//
//

#pragma once

class Shape
{
public:

Shape(double s)
{
   sideLength = s;
}

virtual ~Shape() {};

virtual double getArea() = 0;

virtual double getPerimeter() = 0;

protected:
   double sideLength;

};

