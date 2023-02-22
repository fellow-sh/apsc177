//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 4                                                                 //
// Date: 19-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Description: This program implements a simple trial division algorithm to determine   //
// if an inputted number is a prime number.                                              //
//---------------------------------------------------------------------------------------//

#include <iostream>

// Going to change things up by declaring the main algorithm as a function.
// Then, the interface element of the program is in the main() function.

// Determines if a number is a prime.
bool trial_division(int n);

int main()
{
    while (true)
    {
        // Declare exit character and input number.
        char exit;
        int number;
                    
        // Prompt and read input number.
        std::cout << "Enter an integer greater than 1 to check if it is a prime number: ";
        std::cin >> number;
                    
        // Check if number is a prime.
        if (trial_division(number))
        {
           	// Display number is a prime.
            std::cout << "The number " << number << " is a prime number." << std::endl;
        }
        else
        {
            // Display number is not a prime.
            std::cout << "The number " << number << " is NOT a prime number." << std::endl;
        }
                    
        // Prompt for exit.
        std::cout << "Do you want to enter another number? (y or n): ";
        std::cin >> exit;
        
        // Exit the program.
        if (exit != 'y')
        {
            break;
        }
    }
  	std::cout << "Exiting program ..." << std::endl;
    return 0;
}

// Function that determines if n is a prime.
bool trial_division(int n)
{
    // For every number that is less than sqrt(n).
 	for (int i = 2; i*i < n+1; ++i)
    {
        // If that number divides n, return false
     	if (!(n % i))
        {		
        	  return false;             
        }
    }
    // If no number divides n, return true
    return true;
}