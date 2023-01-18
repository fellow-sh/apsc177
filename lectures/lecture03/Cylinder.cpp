/*----------------------------------------------------------------------------*/
/* APSC 177 Lecture 2                                                         */
/* Date: Jan 12, 2023                                                         */
/* Name: Julian Joaquin 													  */
/* This program calculates the volume of a cylinder							  */
/*----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

// declare PI
const double PI = 3.14159265358979323846;

int main() {
    // declare variables for radius, height, volume
    double radius, height, volume; // pain
    
    // get user input for radius and height
    cout << "radius in cm: ";
    cin >> radius;
    cout << "height in cm: ";
    cin >> height;

    // calculate volume
    volume = PI*radius*radius*height;

    // display everything
    cout << endl;
    cout << "radius is: " << radius << " cm" << endl;
    cout << "height is: " << height << " cm" << endl;
    cout << "volume in cm³: " << volume << endl;
    return (0);
}
