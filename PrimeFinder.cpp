// PrimeFinder.cpp
//
// This program will find prime numbers!
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      cout << "You need to input a number!" << endl;
      return 1;
   }

   stringstream ss(argv[1]);
   
   int x = 0;
   ss >> x;

   if (ss.fail())
   {
      cout << "You need to actually input a number!" << endl;
      return 2;
   }

   vector<int> L;
   L.reserve(100);
   L.push_back(2);
   
   for (int i = 3; i <= x; i++)
   {
      bool isPrime = true;
      for (int j = 0; j < L.size(); j++)
      {
         if (i % L[j] == 0)
         {
            isPrime = false;
            break;
         }
      }
      if (isPrime)
      {
         L.push_back(i);
      }
   }
   
   for (int k = 0; k < L.size(); k++)
   {
      cout << L[k] << " ";
   }
   cout << endl;   

   return 0;
}











