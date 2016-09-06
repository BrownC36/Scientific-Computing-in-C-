// SimplePhysics.cpp
//
// This program uses basic physics to ballistically propagate an object
// through space in 2 dimensions.
//

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <sstream>
using namespace std;

static const double DEG2RAD = M_PI / 180.0;
static const double EPSILON = 1.0e-8;

double computePosition(double initialPos, double initialVel, double acceleration, double time)
{
   return initialPos + initialVel * time + 0.5 * acceleration * time * time;
}

double computeNewTimeStep(double initialPos, double initialVelocity, double acceleration, double time)
{
   double discriminant = initialVelocity * initialVelocity - 4.0 * initialPos * acceleration;
   if (discriminant < 0.0)
   {
      throw std::runtime_error("Could not compute a new time step!");
   }

   double solution = (-initialVelocity + sqrt(discriminant)) / (2.0 * acceleration);
   if (solution < 0.0)
   {
      solution = (-initialVelocity - sqrt(discriminant)) / (2.0 * acceleration);
   }
   return solution;
}

int main(int argc, char **argv)
{
   stringstream ss;

   double initialPositionX = 0.0;
   double initialPositionY = 0.0;
   double positionX        = 0.0;
   double positionY        = 0.0;

   double initialSpeed     = 100.0;
   double launchAngle      = 30.0;
 
   if(argc == 3){
      ss.str(argv[1]);
      ss >> initialSpeed;
      ss.clear();
      ss.str(argv[2]);
      ss >> launchAngle;
      ss.clear();
   }

   double initialVelocityX = initialSpeed * cos(launchAngle * DEG2RAD);
   double initialVelocityY = initialSpeed * sin(launchAngle * DEG2RAD);

   double accelerationX    = 0.0;
   double accelerationY    = -9.81;

   double time     = 0.0;
   double timestep = 0.25;

   std::ofstream dataFile("trajectory.dat");
   dataFile << std::fixed << std::setprecision(8);

   bool complete = false;
   while (!complete)
   {
      positionX = computePosition(initialPositionX, initialVelocityX, accelerationX, time);
      positionY = computePosition(initialPositionY, initialVelocityY, accelerationY, time);

      if (positionY < 0.0)
      {
         time -= timestep;

         positionY = computePosition(initialPositionY, initialVelocityY, accelerationY, time);
         double velocityY = initialVelocityY + accelerationY * time;

         double newTimeStep = computeNewTimeStep(positionY, velocityY, accelerationY, time);
         
         time += newTimeStep;

         positionX = computePosition(initialPositionX, initialVelocityX, accelerationX, time);
         positionY = computePosition(initialPositionY, initialVelocityY, accelerationY, time);
      }

      dataFile << time << "   " << positionX << "   " << positionY << std::endl;

      if (fabs(positionY) < EPSILON && time  > 0.0)
      {
         std::cout << "Done!" << std::endl;
         complete = true;
      }

      time += timestep;
   }

   dataFile.close();

   return 0;
}
