//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 02-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes three inputted letters and outputs them in      //
// alphabetical order, regardless of capitalization. This particular code maximizes the  //
// use of available functions from the standard library that can be called without       //
// including the standard files. Wait, is this bad practice?                             //
//---------------------------------------------------------------------------------------//
#include <iostream>
#include <string>

int main()
{
    // Declare `letters` to count number of letters given by user.
    int letters = 0;
    // Declare `input_chars` to hold the three letters given by user.
    char input_chars[3];

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
            // If character is a letter, add to `input_chars` and increment `letters`.
            if (std::isalpha(input_line[i]) && letters < 3)
            {
                input_chars[letters] = input_line[i];
                ++letters;
            }
            // Behaviour for more than 3 characters is not specified, so throw error.
            else if (std::isalpha(input_line[i]) && letters >= 3)
            {
                throw std::length_error("more than 3 letters inputted");
            }
            else if (!std::isalpha(input_line[i]) && !std::isspace(input_line[i]))
            {
                throw std::invalid_argument("program expects whitespaces or letters");
            }
        }
    }

    // Begin sort procedure.
    // If first char is greater than second char, swap.
    if (std::tolower(input_chars[0]) > std::tolower(input_chars[1]))
    {
        std::swap(input_chars[0], input_chars[1]);
    }
    // If second char is greater than third char, swap.
    if (std::tolower(input_chars[1]) > std::tolower(input_chars[2]))
    {
        std::swap(input_chars[1], input_chars[2]);
    }
    // If (new) first char is greater than (new) second char, swap.
    if (std::tolower(input_chars[0]) > std::tolower(input_chars[1]))
    {
        std::swap(input_chars[0], input_chars[1]);
    }
    
    // Print sorted letters to user.
    std::cout << input_chars << std::endl;
    return(0);
}
