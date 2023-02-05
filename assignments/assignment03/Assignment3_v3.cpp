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

// Since the sorting algorithm at this end only handles 3 values,
// This value cannot be anything else then 3.
const int MAX_LETTERS = 3;

int main()
{
    // Declare `letters` to count number of letters given by user.
    int letters = 0;
    // Declare `input_letters` to hold the three letters given by user.
    char input_letters[MAX_LETTERS];

    // Prompt the user for input.
    // USE THIS COUT STATEMENT IN YOUR CODE. DO NOT CHANGE IT!
    std::cout << "Enter any three letters from the alphabet in any order." << std::endl;
    
    // Begin input loop.
    // Terminate once 3 letters have been given.
    while (letters < MAX_LETTERS)
    {
        // Retrieve an input line from the user.
        char input_char;
        std::cin >> input_char;

        // Iterate over input line to check if each character is a letter.
        // If character is a letter, add to `input_letters` and increment `letters`.
        if (std::isalpha(input_char) && letters < MAX_LETTERS)
        {
            input_letters[letters] = input_char;
            ++letters;
        }
        // Behaviour for more than 3 characters is not specified, so throw error.
        else if (std::isalpha(input_char) && letters >= MAX_LETTERS)
        {
            throw std::length_error("more than 3 letters inputted");
        }
        else if (!std::isalpha(input_char) && !std::isspace(input_char))
        {
            throw std::invalid_argument("program expects whitespaces or letters");
        }
    }

    // Begin sort procedure.
    // If first char is greater than second char, swap.
    if (std::tolower(input_letters[0]) > std::tolower(input_letters[1]))
    {
        std::swap(input_letters[0], input_letters[1]);
    }
    // If second char is greater than third char, swap.
    if (std::tolower(input_letters[1]) > std::tolower(input_letters[2]))
    {
        std::swap(input_letters[1], input_letters[2]);
    }
    // If (new) first char is greater than (new) second char, swap.
    if (std::tolower(input_letters[0]) > std::tolower(input_letters[1]))
    {
        std::swap(input_letters[0], input_letters[1]);
    }
    
    // Print sorted letters to user.
    std::cout << input_letters << std::endl;
    return(0);
}
