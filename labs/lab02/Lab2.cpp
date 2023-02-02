//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 2                                                                 //
// Date: 25-Jan-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program determines the difference between measured and        //
// calcualted angle of attacks from an experiemnt.                                       //
//---------------------------------------------------------------------------------------//

#include <cmath>	// required to use the acos, sin, and abs functions
#include <iostream> // cin, cout byte transfers
using namespace std;

// PI is already defined in the cmath library
const double PI = M_PI;

// define constants used in calculations
const double A = 1.3;
const double B = 95.0;

int main()
{
    // initialize field
    double angle_of_attack;
    double measured_lift_coef;
    double calculated_lift_coef;
    double alpha;
    double diff;
  
  	// Use cin to read an input from the keyboard
    // retrieve data from user from stdin
    cout << "Enter the angle of attack in degrees: ";
    cin >> alpha;
    cout << "Enter the corresponding measured lift coefficient: ";
    cin >> measured_lift_coef;
    
    // calculate lift coefficient
    calculated_lift_coef = A * sin(2 * PI * alpha / B);

    // calculate percent difference and sanity check to prevent divide-by-zero
    if (calculated_lift_coef == 0)
    {
        // if the calculated lift is 0, then the difference must be 0;
        diff = 0;
    }
    else
    {
        // calculate the percent difference
        diff = 100.0 * abs(measured_lift_coef - calculated_lift_coef) / calculated_lift_coef;
    }

  	// The following line of code shows how to print the value of alpha 
  	cout << "Angle of attack in degrees " << alpha << endl;
    cout << "Measured lift coefficient " << measured_lift_coef << endl;
    cout << "Modeled lift coefficient " << calculated_lift_coef << endl;
    cout << "Percent difference " << diff << endl;

    return 0;
}