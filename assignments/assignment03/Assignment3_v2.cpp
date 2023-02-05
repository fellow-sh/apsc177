//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 04-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes three inputted letters and outputs them in      //
// alphabetical order, regardless of capitalization. The number of function calls from   //
// the standard library has been minimized. This code has gone through significant       //
// refactoring to limit code nesting and demonstrate good coding practice.               //
//---------------------------------------------------------------------------------------//
#include <iostream>
#include <string>

void char_bubble_sort(char[], int);
char make_lowercase(char);
bool is_whitespace(char);

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
        std::string input_line;
        std::getline(std::cin, input_line, '\n');

        // Iterate over input line to check if each character is a letter.
        for (int i = 0; i < input_line.length(); ++i)
        {
            bool is_lowercase = 'a' <= input_line[i] && input_line[i] <= 'z';
            bool is_uppercase = 'A' <= input_line[i] && input_line[i] <= 'Z';
            bool is_alpha = is_lowercase || is_uppercase;

            if (letters >= MAX_LETTERS)
            {
                // Behaviour for more than 3 characters is not specified, so throw error.
                std::cout << "Error: exceeded 3 letters,"
                << " exiting with status 1." << std::endl;
                return 0;
            }
            if (!is_alpha && !is_whitespace(input_line[i]))
            {
                // Behaviour for non-alpha characters is not specified, so throw error.
                std::cout << "Error: entered a non-alpha character,"
                << " exiting with status 1." << std::endl;
                return 0;
            }
            // If character is a letter, add to `c`.
            if (is_alpha)
            {
                input_letters[letters] = input_line[i];
                ++letters;
            }
            // There are no operations for whitespaces.
        }
    }

    char_bubble_sort(input_letters, MAX_LETTERS);

    // Print alphabetized letters to user.
    std::cout << input_letters << std::endl;
    return 0;
}

// Sorts an array of chars in alphabetical order.
void char_bubble_sort(char array[], int size)
{
    int n = size - 1;
    while (n >= 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (make_lowercase(array[i]) > make_lowercase(array[i + 1]))
            {
                int tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
            }
        }
        --n;
    }
}

// If character is uppercase, it will be converted to lowercase.
char make_lowercase(char c)
{
    if ('A' <= c && c <= 'Z')
    {
        char lower_c = c + 32;
        return lower_c;
    }
    return c;
}

// Checks if character is a whitespace.
bool is_whitespace(char c)
{
    char whitespaces[4] = {' ', '\t', '\n', '\r'};
    for (char whitespace : whitespaces)
    {
        if (c == whitespace)
        {
            return true;
        }
    }
    return false;
}
