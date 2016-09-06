// Interest.cpp
//
// This program compounds interest.
//

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Conversion.h"

using namespace std;

double computeMonthlyPayment(double, double, double);

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      cout << "Improper usage, please pass in the principle amount, number of payments, and yearly interest rate (as a percentage)" << endl;
      return 1;
   }

   double principle        = stringToDouble(argv[1]);
   double numberOfPayments = stringToDouble(argv[2]);
   double interestRate     = stringToDouble(argv[3]) / 1200.0; // we divide by 1200, since this puts
                                                               // the rate as a monthly, fractional percentage
                                                               // out of 1.0. e.g. 6% yearly => 0.005 monthly rate 

   double monthlyPayment = computeMonthlyPayment(principle, numberOfPayments, interestRate);

   ofstream dataFile("amortization.txt");

   dataFile << "Principle Amount:      " << principle           << endl;
   dataFile << "Number of Payments:    " << numberOfPayments    << endl;
   dataFile << "Yearly Interest Rate:  " << interestRate * 12.0 << endl;
   dataFile << "Monthly Interest Rate: " << interestRate        << endl;
   dataFile << "Monthly Payment:       " << monthlyPayment      << endl;

   dataFile << "Payment | Principle | Interest | Principle Paid | Interest Paid | Rem. Balance\n";

   double principlePaid = 0.0;
   double interestPaid  = 0.0;

   for (int i = 0; i < int(numberOfPayments); ++i)
   {
	  doube monthlyPayment = computeMonthlyPayment(principle, numberOfPayments, interestRate)
	  
      // each payment, x, is equal the sum of its principle and interest components: x = p + i
      /** Here we need to calculate payment and balance values **/
      /** Additionally, as we compute these values, we need to write them to the data file**/

      // you can set the width of a string in the output stream using
      // setw(size)
   }

   dataFile.close();

   return 0;
}

double computeMonthlyPayment(double P, double N, double i)
{
   double payment = ((P*pow(1+i, N))/(pow(1+i, N)-1));
   return payment;
}

