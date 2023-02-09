//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 06-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes three inputted letters and outputs them in      //
// ASCII encoding order (uppercase alphabetized letters, then lowercase alphabetized     //
// letters). This program has been optimized to meet the assignment requirements given   //
// an understanding of C++ from the presented lectures (meaning no arrays).              //
//---------------------------------------------------------------------------------------//
#include <iostream>

int main()
{
    // Declare `c`s to hold the three letters given by user.
    // Null char is used to indicate the variable is empty.
    char letter1 = '\0';
    char letter2 = '\0';
    char letter3 = '\0';

    // Prompt the user for input.
    // USE THIS COUT STATEMENT IN YOUR CODE. DO NOT CHANGE IT!
    std::cout << "Enter any three letters from the alphabet in any order." << std::endl;
    
    // Begin input loop.
    // Terminates once the third letter is not empty.
    while (letter3 == '\0')
    {
        // Retrieve an inputted non-whitespace character from the user.
        // std::cin buffer allows for all characters in a word to be read.
        char input_char;
        std::cin >> input_char;
            
        bool is_lowercase = 'a' <= input_char && input_char <= 'z';
        bool is_uppercase = 'A' <= input_char && input_char <= 'Z';
        bool is_alpha = is_lowercase || is_uppercase;

        if (!is_alpha)
        {
            // Behaviour for non-alpha characters is not specified, so "throw" error.
            std::cout << "Error: entered a non-alpha character, exiting with status 1." << std::endl;
            return 1;
        }
        // If character is a letter, add to `c`.
        // Program checks if letter is "empty" if contains the null char.
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

    // Output letters in ascending ASCII order.
    // Assignment explicitly asks for "if else" statements for this procedure.
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
