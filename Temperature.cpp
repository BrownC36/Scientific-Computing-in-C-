// Temperature.cpp
//
//Convert Fahrenheit to Celsius and Celsius to Farenheit
//

#include <iostream>
#include <cmath>
#include <string>

#include "Conversion.h"

int main(int argc, char *argv[])
{
   double converted = 0.0;

   if (argc < 3)
   {
      cout << "You need to input Temp type and temp!" << endl; 
      return 1;
   }

   double temp = stringToDouble(argv[2]);
 
   if (argv[1] == std::string("CELSIUS"))
   {
      converted = (temp - 32.0) * 5.0 / 9.0;
      cout.precision(4);
      cout << converted << " degress Fahrenheit.\n";
   }

   if(argv[1] == std::string("FAHRENHEIT"))
   {
      converted = (temp*9.0/5.0)+32.0;
      cout.precision(4);
      cout << converted << " degrees Celsius.\n";
   }
   return 0;
}
