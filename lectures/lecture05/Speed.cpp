/*----------------------------------------------------------------------------*/
/* Julian Joaquin 															  */
/* I like trains															  */
/*----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

const double MPS_TO_KPH = 3600.0 / 1000.0;

int main ()
{
    // declare field
    double t1; // seconds
    double t2; // seconds
    double x1; // meters
    double x2; // meters
    double v; // kph
    
    // initialize initial values of time and position
    t1 = 0;
    t2 = 3;
    x1 = 20;
    x2 = 140;
    
    // calculate speed in kph
    v = (x2 - x1) / (t2 - t1) * MPS_TO_KPH;
    
    // output speed
    cout << "The speed is: " << v << endl;
}
