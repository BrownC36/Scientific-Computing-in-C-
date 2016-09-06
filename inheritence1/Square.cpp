// Square.cpp
//
//

#include "Square.h"

Square::Square(double s)
 : Shape(s)
{}

Square::~Square()
{}

double Square::getArea()
{
   return sideLength * sideLength;
}

double Square::getPerimeter()
{
   return 4.0 * sideLength;
}

