//---------------------------------------------------------------------------------------//
// APSC 177 - Lab Section L1B - LAB 3                                                    //
// Date: 08-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program is designed to indicate the number of trains stopped  //
// or cleared at an LRT junction. The code avoids nested if and loops.                   //
//---------------------------------------------------------------------------------------//
#include <iostream>

int main()
{
    // Initialize field.
    int max_trains = 0;
    int has_max_trains = -1;

    // Define variables for number of trains per track.
    int track1_trains = 0;
    int track2_trains = 0;
    int track3_trains = 0;
    int track4_trains = 0;

    // Check which track has greatest number of trains while inputting.
    // Track has greatest number of trains is read with respect to track priority.
    // Behaviour for user inputting non-integer characters is undefined.
    // Behaviour for negative integers is undefined.
    std::cout << "Enter the number of trains on track 1. ";
    std::cin >> track1_trains;
    std::cout << "Enter the number of trains on track 2. ";
    std::cin >> track2_trains;
    std::cout << "Enter the number of trains on track 3. ";
    std::cin >> track3_trains;
    std::cout << "Enter the number of trains on track 4. ";
    std::cin >> track4_trains;

    // Find which track has the greatest number of trains.
    if (track1_trains >= max_trains)
    {
        has_max_trains = 0;
        max_trains = track1_trains;
    }
    if (track2_trains >= max_trains)
    {
        has_max_trains = 1;
        max_trains = track2_trains;
    }
    if (track3_trains >= max_trains)
    {
        has_max_trains = 2;
        max_trains = track3_trains;
    }
    if (track4_trains >= max_trains)
    {
        has_max_trains = 3;
        max_trains = track4_trains;
    }

    // Output trains on tracks for Track 1.
    if (has_max_trains == 0 && track1_trains > 4)
    {
        std::cout << "Track 1 has 1 train cleared and " << track1_trains - 1 << " train(s) stopped." << " Track 1 alert!" << std::endl;
    }
    else if (has_max_trains == 0)
    {
        std::cout << "Track 1 has 1 train cleared and " << track1_trains - 1 << " train(s) stopped." << std::endl;
    }
    else
    {
        std::cout << "Track 1 has " << track1_trains << " train(s) stopped." << std::endl;
    }


    // Output trains on tracks for Track 2.
    if (has_max_trains == 1 && track2_trains > 4)
    {
        std::cout << "Track 2 has 1 train cleared and " << track2_trains - 1 << " train(s) stopped." << " Track 2 alert!" << std::endl;
    }
    else if (has_max_trains == 1)
    {
        std::cout << "Track 2 has 1 train cleared and " << track2_trains - 1 << " train(s) stopped." << std::endl;
    }
    else
    {
        std::cout << "Track 2 has " << track2_trains << " train(s) stopped." << std::endl;
    }


    // Output trains on tracks for Track 3.
    if (has_max_trains == 2 && track3_trains > 4)
    {
        std::cout << "Track 3 has 1 train cleared and " << track3_trains - 1 << " train(s) stopped." << " Track 3 alert!" << std::endl;
    }
    else if (has_max_trains == 2)
    {
        std::cout << "Track 3 has 1 train cleared and " << track3_trains - 1 << " train(s) stopped." << std::endl;
    }
    else
    {
        std::cout << "Track 3 has " << track3_trains << " train(s) stopped." << std::endl;
    }

    
    // Output trains on tracks for Track 4.
    if (has_max_trains == 3 && track4_trains > 4)
    {
        std::cout << "Track 4 has 1 train cleared and " << track4_trains - 1 << " train(s) stopped." << " Track 4 alert!" << std::endl;
    }
    else if (has_max_trains == 3)
    {
        std::cout << "Track 4 has 1 train cleared and " << track4_trains - 1 << " train(s) stopped." << std::endl;
    }
    else
    {
        std::cout << "Track 4 has " << track4_trains << " train(s) stopped." << std::endl;;
    }
    return 0;
}
