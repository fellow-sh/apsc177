//---------------------------------------------------------------------------------------//
// APSC 177 Assignment 5                                                                 //
// Date: 02-Mar-2023                                                                     //
// Name: Julian Joaquin                                                                  //
// Student ID Number: 52754413                                                           //
// Brief Description: This program takes the input of two vectors and returns their dot  //
// product.                                                                              //
//---------------------------------------------------------------------------------------//

#include <iostream>
using namespace std;

int main()
{
    // declare dimension
    int dimension;

    cout << "This program calculates the dot product of two vectors." << endl;
    
    // prompt and read vector dimension
	cout << "Enter the dimension (length) of the two vectors: ";
    cin >> dimension;

    // EDGE CASE: If dimension does not allow for a vector, exit with STATUS 1
    if (!dimension > 1) {
        return 1;
    }

    // prompt for first vector   
    cout << "Enter the " << dimension << " components of the first vector separated by spaces. " << endl;
    // declare and read first vector
    double vector1[dimension];
    for (int i = 0; i < dimension; ++i)
    {
        cin >> vector1[i];
    }
   
    // prompt for second vector
    cout << "Enter the " << dimension << " components of the second vector separated by spaces. " << endl;
    // declare and read second vector
    double vector2[dimension];
    for (int i = 0; i < dimension; ++i)
    {
        cin >> vector2[i];
    }

    // declare and calculate dot product
    double dot_product = 0;
    for (int dim = 0; dim < dimension; ++dim)
    {
        // dot product is sum of the products of each dimension
        dot_product += vector1[dim] * vector2[dim];
    }

    // display dot product
    cout << "The dot product of the two vectors is " << dot_product << endl;

    return 0;
}
