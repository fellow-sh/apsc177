// This program implements the trial division algorithm

#include <iostream>
#include <vector>

std::vector<int> sieve(int n);
bool sieve_test(int n);

int main()
{
    while(true)
    {
        int number;
        char exit;
        std::cout << "Enter an integer greater than 1 to check if it is a prime number: ";
        std::cin >> number;
        if(sieve_test(number))
        {
            std::cout << "The number " << number << " is a prime number." << std::endl;
        }
        else
        {
            std::cout << "The number " << number << " is NOT a prime number." << std::endl;
        }
        std::cout << "Do you want to enter another number? (y or n): ";
        std::cin >> exit;
        if (exit != 'y')
        {
            break;
        }
    }
    std::cout << "Exiting program ..." << std::endl;
   
    return 0;
}

std::vector<int> sieve(int n)
{
    std::vector<int> numbers(n-1, 1);
    for (int i = 0; i*i < n; ++i)
    {
        if (numbers[i])
        {
            for (int j = (i+2)*(i+2); j < n + 1; j += i+2)
            {
                numbers[j-2] = 0;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 0; i < n; ++i)
    {
        if (numbers[i])
        {
            primes.push_back(i + 2);
        }
    }
    return primes;
}

bool sieve_test(int n)
{
    if (n < 3 || n & 2)
    {
        return false;
    }
    std::vector<int> primes = sieve(n);
    if (primes.back() == n)
    {
        return true;
    }
    for (int p : primes)
    {
        if (!(n % p))
        {
            return false;
        }
    }
    return true;
}