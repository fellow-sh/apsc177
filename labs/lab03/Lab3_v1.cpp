//---------------------------------------------------------------------------------------//
// APSC 177 - Lab Section L1B - LAB 3                                                    //
// Date: 08-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program is designed to indicate the number of trains stopped  //
// or cleared at an LRT junction.                                                        //
//---------------------------------------------------------------------------------------//
#include <iostream>

const int TRACKS = 4;
const int TRAIN_WARNING_THRESHOLD = 4;

int main()
{
    // Initialize field.
    int most_trains = 0;
    int most_trains_index = -1;

    // Define variables for number of trains per track.
    int track_trains[TRACKS];

    // Check which track has greatest number of trains while inputting.
    // Track has greatest number of trains is read with respect to track priority.
    // Behaviour for user inputting non-integer characters is undefined.
    // Behaviour for negative integers is undefined.
    for (int i = 0; i < TRACKS; ++i)
    {
        // Prompt user for input and read number of trains.
        std::cout << "Enter the number of trains on track " << i + 1 << ". ";
        std::cin >> track_trains[i];

        // If number of trains is the greater then previous maximum, replace.
        if (track_trains[i] >= most_trains)
        {
            most_trains_index = i;
            most_trains = track_trains[i];
        }
        // Format output in case of bash here string input.
        if (std::cin.peek() != '\n')
        {
            std::cout << '\n';
        }
    }

    // Output the number of trains per track.
    // Output is formatted while checking conditions.
    for (int i = 0; i < TRACKS; ++i)
    {
        std::cout << "Track " << i + 1 << " has ";

        // Output trains cleared and stopped if track has most trains.
        if (most_trains_index == i)
        {
            std::cout << "1 train cleared and " << track_trains[i] - 1 << " train(s) stopped.";

            // If number of trains exceeds threshold, ouput alert.
            if (track_trains[i] > TRAIN_WARNING_THRESHOLD)
            {
                std::cout << " Track " << i + 1 << " alert!";
            }
        }
        // Otherwise only output stopped trains.
        else
        {
            std::cout << track_trains[i] << " train(s) stopped.";
        }
        std::cout << "\n";
    }

    // Flush stream.
    std::cout << std::endl;
    return 0;
}
