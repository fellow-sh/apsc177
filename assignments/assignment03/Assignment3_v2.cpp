//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 01-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes three inputted letters and outputs them in      //
// alphabetical order, regardless of capitalization. The number of function calls from   //
// the standard library has been minimized in this code.                                 //
//---------------------------------------------------------------------------------------//
#include <iostream>
#include <string>

int main()
{
    // Declare `letters` to count number of letters given by user.
    int letters = 0;
    // Declare `input_letters` to hold the three letters given by user.
    char input_letters[3];

    // Prompt the user for input.
    // USE THIS COUT STATEMENT IN YOUR CODE. DO NOT CHANGE IT!
    std::cout << "Enter any three letters from the alphabet in any order." << std::endl;
    
    // Begin input loop.
    // Terminate once 3 letters have been given.
    while (letters < 3)
    {
        // Retrieve an input line from the user.
        std::string input_line;
        std::getline(std::cin, input_line, '\n');

        // Iterate over input line to check if each character is a letter.
        for (int i = 0; i < input_line.length(); ++i)
        {
            bool is_lowercase = 'a' <= input_line[i] && input_line[i] <= 'z';
            bool is_uppercase = 'A' <= input_line[i] && input_line[i] <= 'Z';

            // If character is a letter, add to `input_letters` and increment `letters`.
            if ((is_lowercase || is_uppercase) && letters < 3)
            {
                input_letters[letters] = input_line[i];
                ++letters;
            }
            // Behaviour for more than 3 characters is not specified, so throw error.
            else if ((is_lowercase || is_uppercase) && letters >= 3)
            {
                std::cout << "Error: exceeded 3 letters, exiting." << std::endl;
                //exit(1);
                return(0);
            }
        }
    }

    // Track which letters are capitalized using companion boolean array.
    // Reduce all letters to lowercase.
    bool capitalized_letter[3] = {false};
    for (int i = 0; i < 3; ++i)
    {
        if ('A' <= input_letters[i] && input_letters[i] <= 'Z')
        {
            input_letters[i] += 32;
            capitalized_letter[i] = true;
        }
    }

    // Begin sort procedure.
    // If first char is greater than second char, swap.
    if (input_letters[0] > input_letters[1])
    {
        char ctmp = input_letters[1];
        input_letters[1] = input_letters[0];
        input_letters[0] = ctmp;

        bool btmp = capitalized_letter[1];
        capitalized_letter[1] = capitalized_letter[0];
        capitalized_letter[0] = btmp;
    }
    // If second char is greater than third char, swap.
    if (input_letters[1] > input_letters[2])
    {
        char ctmp = input_letters[2];
        input_letters[2] = input_letters[1];
        input_letters[1] = ctmp;

        bool btmp = capitalized_letter[2];
        capitalized_letter[2] = capitalized_letter[1];
        capitalized_letter[1] = btmp;
    }
    // If (new) first char is greater than (new) second char, swap.
    if (input_letters[0] > input_letters[1])
    {
        char ctmp = input_letters[1];
        input_letters[1] = input_letters[0];
        input_letters[0] = ctmp;
        
        bool btmp = capitalized_letter[1];
        capitalized_letter[1] = capitalized_letter[0];
        capitalized_letter[0] = btmp;
    }

    // Return respective letters to uppercase.
    for (int i = 0; i < 3; ++i)
    {
        if (capitalized_letter[i])
        {
            input_letters[i] -= 32;
        }
    }

    // Print alphabetized letters to user.
    std::cout << input_letters << std::endl;
    return(0);
}
