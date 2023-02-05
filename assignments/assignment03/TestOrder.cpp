#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

int main ()
{
    std::vector<char> list = {'r', 'u', 'k'};
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(list.begin(), list.end(), std::default_random_engine(seed));

    std::cout << list[0] << list[1] << list[2] << std::endl;

    char c1 = list[0], c2 = list[1], c3 = list[2];
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