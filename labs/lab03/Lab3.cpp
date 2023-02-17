//---------------------------------------------------------------------------------------//
// APSC 177 - Lab Section L1B - LAB 3                                                    //
// Date: 11-Feb-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program is designed to indicate the number of trains stopped  //
// or cleared at an LRT junction. I would recommend beginning students to use this       //
// method.                                                                               //
//---------------------------------------------------------------------------------------//
#include <iostream>

int main()
{
    int track1;
    int track2;
    int track3;
    int track4;

    std::cout << "Enter the number of trains on track 1. ";
    std::cin >> track1;
    std::cout << "Enter the number of trains on track 2. ";
    std::cin >> track2;
    std::cout << "Enter the number of trains on track 3. ";
    std::cin >> track3;
    std::cout << "Enter the number of trains on track 4. ";
    std::cin >> track4;

    if (track1 > track2 && track1 > track3 && track1 > track4)
    {
        std::cout << "Track 1 has 1 train cleared and " << track1 - 1 << " train(s) stopped.";
        if (track1 > 4)
        {
            std::cout << " Track 1 alert!";
        }
        std::cout << "\n";
        std::cout << "Track 2 has " << track2 << " train(s) stopped.\n";
        std::cout << "Track 3 has " << track3 << " train(s) stopped.\n";
        std::cout << "Track 4 has " << track4 << " train(s) stopped." << std::endl;
    }
    if (track2 >= track1 && track2 > track3 && track2 > track4)
    {
        std::cout << "Track 1 has " << track2 << " train(s) stopped.\n";
        std::cout << "Track 2 has 1 train cleared and " << track2 - 1 << " train(s) stopped.";
        if (track2 > 4)
        {
            std::cout << " Track 2 alert!";
        }
        std::cout << "\n";
        std::cout << "Track 3 has " << track3 << " train(s) stopped.\n";
        std::cout << "Track 4 has " << track4 << " train(s) stopped." << std::endl;
    }
    if (track3 >= track1 && track3 >= track2 && track3 > track4)
    {
        std::cout << "Track 1 has " << track3 << " train(s) stopped.\n";
        std::cout << "Track 2 has " << track3 << " train(s) stopped.\n";
        std::cout << "Track 3 has 1 train cleared and " << track3 - 1 << " train(s) stopped.";
        if (track3 > 4)
        {
            std::cout << " Track 3 alert!";
        }
        std::cout << "Track 4 has " << track4 << " train(s) stopped." << std::endl;
    }
    if (track4 >= track1 && track4 >= track2 && track4 >= track3)
    {
        std::cout << "Track 1 has " << track3 << " train(s) stopped.\n";
        std::cout << "Track 2 has " << track2 << " train(s) stopped.\n";
        std::cout << "Track 3 has " << track3 << " train(s) stopped.\n";
        std::cout << "Track 4 has 1 train cleared and " << track4 - 1 << "train(s) stopped.";
        if (track4 > 4)
        {
            std::cout << " Track 4 alert!";
        }
        std::cout << std::endl;
    }
    return 0;
}
