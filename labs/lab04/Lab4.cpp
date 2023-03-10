//---------------------------------------------------------------------------------------//
// APSC 177 - Lab Section L1B - Lab 4                                                    //
// Date: March 8, 2023                                                                   //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Description: This program calculates the statistical mean, variance, and standard     //
// deviation of a set of real numbers.                                                   //
//---------------------------------------------------------------------------------------//

#include <iostream>
#include <cmath>

double average(double arr[], int size);
double variance(double arr[], int size);
double stdev(double arr[], int size);

int main()
{
    int n;

    // prompt for the set size `n`
    std::cout << "How many numbers do you wish to enter? ";
    std::cin >> n;
    double arr[n];

    // prompt for the sample set `arr`
    std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // output the average
    double avg = average(arr, n);
    std::cout << "The average is " << avg << "\n";

    // output the variance
    double var = variance(arr, n);
    std::cout << "The variance is " << var << "\n";

    // output the standard deviation
    double stdv = stdev(arr, n);
    std::cout << "The standard deviation is " << stdv << std::endl;
}

/**
 * Returns the mean of a sample set of numbers from a array with a set size.
 * 
 * @param arr The array containing the sample set.
 * @param size The size of the array, or the number of samples in the set.
 * @return The average of the set.
 */
double average(double arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i] / size;
    }
    return sum;
}

/**
 * Returns the variance of a sample set of numbers from an array with a set
 * size.
 * 
 * @param arr The array containing the sample set.
 * @param size The size of the array, or the number of samples in the set.
 * @return The variance of the set. 
 */
double variance(double arr[], int size)
{
    double sum = 0;
    double mu = average(arr, size);
    for (int i = 0; i < size; ++i)
    {
        sum += (arr[i] - mu)*(arr[i] - mu) / (size - 1);
    }
    return sum;
}

/**
 * Returns the standard deviation of a sample set of numbers from an array
 * with a set size.
 * 
 * @param arr The array containing the sample set.
 * @param size The size of the array, or the number of samples in the set.
 * @return The standard deviation of the set. 
 */
double stdev(double arr[], int size)
{
    double var = variance(arr, size);
    double stdevp = std::sqrt(var);
    return stdevp;
}
