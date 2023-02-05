//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 02-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes three inputted letters and outputs them in      //
// ASCII encoding order (uppercase alphabetized letters, then lowercase alphabetized     //
// letters). This program has been coded to minimize its sophisitication.                //
//---------------------------------------------------------------------------------------//
#include <iostream>

int main()
{
    // Declare `c`s to hold the three letters given by user.
    // Null char is used to indicate the variable is empty.
    char letter1 = '\0', letter2 = '\0', letter3 = '\0';

    // Prompt the user for input.
    // USE THIS COUT STATEMENT IN YOUR CODE. DO NOT CHANGE IT!
    std::cout << "Enter any three letters from the alphabet in any order." << std::endl;
    
    // Begin input loop.
    // Terminate once the third letter is defined.
    while (letter3 == '\0')
    {
        // Retrieve an input line from the user.
        char input_line[256];
        std::cin >> input_line;

        // Iterate over input line to check if each character is a letter.
        for (int i = 0; i < input_line[i] != '\0'; ++i)
        {
            char input_char = input_line[i];
            
            bool is_lowercase = 'a' <= input_char && input_char <= 'z';
            bool is_uppercase = 'A' <= input_char && input_char <= 'Z';
            bool is_alpha = is_lowercase || is_uppercase;

            if (letter3 != '\0')
            {
                // Behaviour for more than 3 characters is not specified, so throw error.
                std::cout << "Error: exceeded 3 letters, exiting with status 1." << std::endl;
                return 0;
            }
            if (!is_alpha)
            {
                // Behaviour for non-alpha characters is not specified, so throw error.
                std::cout << "Error: entered a non-alpha character, exiting with status 1." << std::endl;
                return 0;
            }
            // If character is a letter, add to `c`.
            if (letter1 == '\0')
            {
                letter1 = input_char;
            }
            else if (letter2 == '\0')
            {
                letter2 = input_char;
            }
            else if (letter3 == '\0')
            {
                letter3 = input_char;
            }
        }
    }

    // Begin sort procedure.
    // Print ACSII-ordered letters to user.
    // Ordered ouptut is handled in case-by-case conditions.
    if (letter1 < letter2)
    {
        if (letter2 < letter3)
        {
            std::cout << letter1 << letter2 << letter3 << std::endl;
        }
        else if (letter1 < letter3)
        {
            std::cout << letter1 << letter3 << letter2 << std::endl;
        }
        else
        {
            std::cout << letter3 << letter1 << letter2 << std::endl;
        }
    }
    else
    {
        if (letter1 < letter3)
        {
            std::cout << letter2 << letter1 << letter3 << std::endl;
        }
        else if (letter2 < letter3)
        {
            std::cout << letter2 << letter3 << letter1 << std::endl;
        }
        else
        {
            std::cout << letter3 << letter2 << letter1 << std::endl;
        }
    }

    return 0;
}
