//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 3                                                                 //
// Date: 31-Jan-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes a string of three characters and outputs the    //
// same string in alphabetical order.                                                    //
//---------------------------------------------------------------------------------------//
#include <iostream>
#include <string>

int main()
{
    // declare `letters` to count number of letters given by user
    // declare `input_string` to hold the three letters given by user
    int letters = 0;
    char input_string[3];

    // prompt user for input
    // USE THIS COUT STATEMENT IN YOUR CODE. DO NOT CHANGE IT!
    std::cout << "Enter any three letters from the alphabet in any order." << std::endl;
    
    // begin input loop
    // terminate once 3 letters have been given
    while (letters < 3)
    {
        // retrieve an input line from the user
        std::string input_line;
        std::getline(std::cin, input_line, '\n');

        // iterate over input line to check if each character is a letter
        for (int i = 0; i < input_line.length(); ++i)
        {
            bool is_lowercase = 'a' <= input_line[i] && input_line[i] <= 'z';
            bool is_uppercase = 'A' <= input_line[i] && input_line[i] <= 'Z';

            // if character is a letter, add to `input_string` and increment `letters`
            if ((is_lowercase || is_uppercase) && letters < 3)
            {
                input_string[letters] = input_line[i];
                ++letters;
            }
            // behaviour for more than 3 characters is not specified, so throw error
            else if ((is_lowercase || is_uppercase) && letters >= 3)
            {
                throw std::length_error("more than 3 letters inputted");
                exit(0);
            }
        }
    }

    // begin sort procedure
    // if first char is greater than second char, swap
    if (std::tolower(input_string[0]) > std::tolower(input_string[1]))
    {
        char tmp = input_string[1];
        input_string[1] = input_string[0];
        input_string[0] = tmp;
    }
    // if second char is greater than third char, swap
    if (std::tolower(input_string[1]) > std::tolower(input_string[2]))
    {
        char tmp = input_string[2];
        input_string[2] = input_string[1];
        input_string[1] = tmp;
    }
    // if (new) first char is greater than (new) second char, swap
    if (std::tolower(input_string[0]) > std::tolower(input_string[1]))
    {
        char tmp = input_string[1];
        input_string[1] = input_string[0];
        input_string[0] = tmp;
    }

    // print sorted letters to user
    std::cout << input_string << std::endl;
    return 0;
}
