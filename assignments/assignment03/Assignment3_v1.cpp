//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 31-Jan-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes three inputted letters and outputs them in      //
// ASCII encoding order (uppercase alphabetized letters, then lowercase alphabetized     //
// letters).                                                                             //
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
            bool is_alpha = is_lowercase || is_uppercase;

            bool is_whitespace = input_line[i] == ' ' || input_line[i] == '\t' || input_line[i] == '\n';

            if (letters >= 3)
            {
                // Behaviour for more than 3 characters is not specified, so throw error.
                std::cout << "Error: exceeded 3 letters, exiting with status 1." << std::endl;
                return 0;
            }
            if (!is_alpha && !is_whitespace)
            {
                // Behaviour for non-alpha characters is not specified, so throw error.
                std::cout << "Error: entered a non-alpha character, exiting with status 1." << std::endl;
                return 0;
            }
            // If character is a letter, add to `c`.
            if (is_alpha)
            {
                input_letters[letters] = input_line[i];
                ++letters;
            }
        }
    }

    // Begin sort procedure.
    // If first char is greater than second char, swap.
    if (input_letters[0] > input_letters[1])
    {
        char ctmp = input_letters[1];
        input_letters[1] = input_letters[0];
        input_letters[0] = ctmp;
    }
    // If second char is greater than third char, swap.
    if (input_letters[1] > input_letters[2])
    {
        char ctmp = input_letters[2];
        input_letters[2] = input_letters[1];
        input_letters[1] = ctmp;
    }
    // If (new) first char is greater than (new) second char, swap.
    if (input_letters[0] > input_letters[1])
    {
        char ctmp = input_letters[1];
        input_letters[1] = input_letters[0];
        input_letters[0] = ctmp;
    }

    // Print ACSII-ordered letters to user.
    std::cout << input_letters << std::endl;
    return(0);
}
