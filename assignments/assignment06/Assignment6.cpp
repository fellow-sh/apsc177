//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 6                                                                 //
// Date: 2March 11, 2023                                                                 //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: A program that displays a formatted table of trig functions based  //
// on the input of two angles.                                                           //
//---------------------------------------------------------------------------------------//

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{   
    // declare program variables
    double angle1;
    double angle2;
    int left_width = 15;
    int right_width = 9;

    // prompt and read angle 1
  	cout << "Enter an angle between -360 and 360 degrees: ";
    cin >> angle1;
    
    // prompt and read angle 2
    cout << "Enter an angle between -360 and 360 degrees: ";
    cin >> angle2;

    // convert angle from degrees to radians
    double rad1 = angle1 *  M_PI / 180.0;
    double rad2 = angle2 *  M_PI / 180.0;

    // print the first row
    cout << setprecision(2) << fixed;
    cout << left << setw(left_width) << "Angle (degrees)"
         << right << setw(right_width) << "cos"
         << setw(right_width) << "sin"
         << setw(right_width) << "cosh"
         << setw(right_width) << "sinh" << '\n';

    // print the second row
    cout << left << setw(left_width) << angle1
         << right << setw(right_width) << cos(rad1)
         << setw(right_width) << sin(rad1)
         << setw(right_width) << cosh(rad1)
         << setw(right_width) << sinh(rad1) << "\n";
         
    // print the third row
    cout << left << setw(left_width) << angle2
         << right << setw(right_width) << cos(rad2)
         << setw(right_width) << sin(rad2)
         << setw(right_width) << cosh(rad2)
         << setw(right_width) << sinh(rad2) << "\n";

    return 0;
}

// EXPECTED OUTPUT
/*
Enter an angle between -360 and 360 degrees: -180 
Enter an angle between -360 and 360 degrees: 180          
Angle (degrees)      cos      sin     cosh     sinh 
-180.0             -1.00    -0.00    11.59   -11.55 
180.0              -1.00     0.00    11.59    11.55 
*/

// Do not change the cout statements in the starter code.
// You will have to add more cout statements.
// Use the following strings in your code
// "Angle (degrees)"
// "cos"
// "sin"
// "cosh" 
// "sinh"
