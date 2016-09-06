// main.cpp
//
//

#include <iostream>
#include <vector>

#include "Circle.h"
#include "Octagon.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

int main()
{
   Circle a(1.0);
   Square b(4.0);
   Triangle c(2.0);
   Octagon d(1.0);
   
   
   vector<Shape*> shapeVector;

   shapeVector.push_back(&a);
   shapeVector.push_back(&b);
   shapeVector.push_back(&c);
   shapeVector.push_back(&d);

   Circle *cPtr = new Circle(10.0);

   shapeVector.push_back(cPtr);
   
   for (int i = 0; shapeVector.size(); i++)
   {
      cout << shapeVector[i]->getArea() << "   "
           << shapeVector[i]->getPerimeter() << endl;
   }

   delete cPtr;

}

