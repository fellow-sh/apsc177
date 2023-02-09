//---------------------------------------------------------------------------------------//
// APSC 177 - Lab Section L1B - LAB 3                                                    //
// Date: 08-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program is designed to indicate the number of trains stopped  //
// or cleared at an LRT junction.                                                        //
//---------------------------------------------------------------------------------------//
#include <iostream>

const int TRAIN_WARNING_THRESHOLD = 4;

int main()
{
    // Initialize field.
    int most_trains = 0;
    int most_trains_index = -1;

    // Define variables for number of trains per track.
    int track1_trains;
    int track2_trains;
    int track3_trains;
    int track4_trains;

    // Check which track has greatest number of trains while inputting.
    // Track has greatest number of trains is read with respect to track priority.
    // Behaviour for user inputting non-integer characters is undefined.
    // Behaviour for negative integers is undefined.
    for (int i = 0; i < 4; ++i)
    {
        // Prompt user for input and read number of trains.
        int input_trains;
        
        std::cout << "Enter the number of trains on track " << i + 1 << ". ";
        std::cin >> input_trains;

        switch (i)
        {
        case 0:
            track1_trains = input_trains;
            break;
        case 1:
            track2_trains = input_trains;
            break;
        case 2:
            track3_trains = input_trains;
            break;
        case 3:
            track4_trains = input_trains;
            break;
        }
        // If number of trains is the greater then previous maximum, replace.
        if (input_trains >= most_trains)
        {
            most_trains_index = i;
            most_trains = input_trains;
        }
    }

    // Output the number of trains per track.
    // Output is formatted while checking conditions.
    for (int i = 0; i < 4; ++i)
    {
        int trains;
        switch (i)
        {
        case 0:
            trains = track1_trains;
            break;
        case 1:
            trains = track2_trains;
            break;
        case 2:
            trains = track3_trains;
            break;
        case 3:
            trains = track4_trains;
            break;
        }

        std::cout << "Track " << i + 1 << " has ";

        // Output trains cleared and stopped if track has most trains.
        if (most_trains_index == i)
        {
            std::cout << "1 train cleared and " << trains - 1 << " train(s) stopped.";

            // If number of trains exceeds threshold, ouput alert.
            if (trains > TRAIN_WARNING_THRESHOLD)
            {
                std::cout << " Track " << i + 1 << " alert!";
            }
        }
        // Otherwise only output stopped trains.
        else
        {
            std::cout << trains << " train(s) stopped.";
        }
        std::cout << '\n';
    }

    // Flush stream.
    std::cout << std::endl;
    return 0;
}
