//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 2                                                                 //
// Date: 26-Jan-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: A program that converts degrees Celcius to degrees Fahrenheit.     //
//---------------------------------------------------------------------------------------//

#include <iostream>
using namespace std;

int main()
{
    double temp_C;  // temperature in degrees Celsius
  
    // prompt user to enter a temperature in degrees Celsius
    cout << "Enter a temperature in degrees Celsius: ";
    
    // read in the temperature in degrees Celsius
    cin >> temp_C;
 
    // convert Celsius to Fahrenheit
    double temp_F = 9.0 / 5.0 * temp_C + 32.0;
    
    // display temperature in Celsius and Fahrenheit 
    // Use the following strings in your program:
	// " degrees Celsius is " 
	// " degrees Fahrenheit." 
	//
    cout << temp_C << " degrees Celsius is " << temp_F << " degrees Fahrenheit." << endl;
   
    return 0;
}

// Note that there is a period (.) after Fahrenheit
// Note the spaces
// Remember that your output must match the format on the assignment description character-by-character.