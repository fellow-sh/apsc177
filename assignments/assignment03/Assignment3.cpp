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
#include <string>

int main()
{
    // Declare `letters` to count number of letters given by user.
    int letters = 0;
    // Declare `c`s to hold the three letters given by user.
    // '\0' is used to indicate the variable is empty.
    char c1('\0'), c2('\0'), c3('\0');

    // Prompt the user for input.
    // USE THIS COUT STATEMENT IN YOUR CODE. DO NOT CHANGE IT!
    std::cout << "Enter any three letters from the alphabet in any order." << std::endl;
    
    // Begin input loop.
    // Terminate once 3 letters have been given.
    while (letters < 3)
    {
        // Retrieve an input line from the user.
        std::string input_line;
        std::getline(std::cin, input_line);

        // Iterate over input line to check if each character is a letter.
        for (int i = 0; i < input_line.length(); ++i)
        {
            char read_char = input_line[i];

            bool is_lowercase = 'a' <= read_char && read_char <= 'z';
            bool is_uppercase = 'A' <= read_char && read_char <= 'Z';
            bool is_alpha = is_lowercase || is_uppercase;

            // If character is a letter, add to `c` and increment `letters`.
            if (is_alpha) ++letters;
            if (is_alpha && c1 == '\0') c1 = read_char;
            else if (is_alpha && c2 == '\0') c2 = read_char;
            else if (is_alpha && c3 == '\0') c3 = read_char;
            else if (letters > 3)
            {
                // Behaviour for more than 3 characters is not specified, so throw error.
                std::cout << "Error: exceeded 3 letters, exiting with status 1." << std::endl;
                return 0;
            }
        }
    }

    // Begin sort procedure.

    // Is c1 before c2?
    bool is_order1_2 = c1 < c2;
    // Is c1 before c3?
    bool is_order1_3 = c1 < c3;
    // Is c2 before c3?
    bool is_order2_3 = c2 < c3;

    // Print ACSII-ordered letters to user.
    // Ordered ouptut is handled in case-by-case conditions.

    // c1 c2 c3
    if (is_order1_2 && is_order1_3 && is_order2_3)
    {
        std::cout << c1 << c2 << c3 << std::endl;
    }
    // c2 c1 c3
    if (!is_order1_2 && is_order1_3 && is_order2_3)
    {
        std::cout << c2 << c1 << c3 << std::endl;
    }
    // c2 c3 c1
    if (!is_order1_2 && !is_order1_3 && is_order2_3)
    {
        std::cout << c2 << c3 << c1 << std::endl;
    }
    // c1 c3 c2
    if (is_order1_2 && is_order1_3 && !is_order2_3)
    {
        std::cout << c1 << c3 << c2 << std::endl;
    }
    // c3 c1 c2
    if (is_order1_2 && !is_order1_3 && !is_order2_3)
    {
        std::cout << c3 << c1 << c2 << std::endl;
    }
    // c3 c2 c1
    if (!is_order1_2 && !is_order1_3 && !is_order2_3)
    {
        std::cout << c3 << c2 << c1 << std::endl;
    }

    return 0;
}
