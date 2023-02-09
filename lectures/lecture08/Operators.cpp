#include <iostream>

int main()
{
    // initialize field
    double x;
    double y;
    char _operator;

    // prompt reader for input
    std::cout << "Enter two numbers, then the operator to evaluate the two numbers with." << std::endl;
    
    // take user input
    std::cin >> x >> y >> _operator;

    // determine operation and execute
    switch (_operator)
    {
    case '+':
        std::cout << x << " + " << y << " = " << x + y << std::endl;
        break;
    case '-':
        std::cout << x << " - " << y << " = " << x - y << std::endl;
        break;
    case '*':
        std::cout << x << " * " << y << " = " << x * y << std::endl;
        break;
    case '/':
        std::cout << x << " / " << y << " = " << x / y << std::endl;
        break;
    default:
        std::cout << "Error. something went wrong >:(. Exiting with status 1." << std::endl;
        return 1;
    }
    return 0;
}

