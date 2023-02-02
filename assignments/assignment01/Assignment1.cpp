//--------------------------------------------------------------------------------------//
//  APSC 177 Assignment 1                                                               //
//  Date: 17th January 2023                                                             //
//  Name: Julian Joaquin                                                                //
//  Student ID Number: 52754413                                                         //
//  Brief Description: A program that evaluates the volume of a box.                    //
//--------------------------------------------------------------------------------------//

#include <iostream>

using namespace std;

int main()
{
    double width;  // width of box in cm
    double depth;
    double height;
    double volume;
  
    // assign values to box width, depth and height (all in cm)
    width = 15;
    depth = 10;
    height = 5.5;
  
    // compute the volume of the box
    volume = width * depth * height;

    // display box width, depth, height, and volume on display
    cout << "width of box = " << width << " cm" << endl;
    // use the following strings to display the remaining variables
    // "depth of box = "
	// " cm"
	// "height of box = "
	// "volume of box = "
	// " cm^3"
    cout << "depth of box = " << depth << " cm" << endl;
    cout << "height of box = " << height << " cm" << endl;
    cout << "volume of box = " << volume << " cm^3" << endl;
    
    return 0;
}
// Note that there is no period (.) after cm or cm^3
// Note the spaces
// Remember that your output must match the format on the assignment description character-by-character. 
// Typos will lead to a mark of zero. This is why the strings that you need are given above.
