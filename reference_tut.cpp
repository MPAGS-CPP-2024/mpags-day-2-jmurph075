#include <iostream>

void swap( double& a, double& b)
{ // the & signs declares that 'a' and 'b' are refeences 
    // no new object is created, they simply refer to an existing object
    //this then allows functions to act ont he ACTUAL OBJECTS passed to them rather than create a copy and do things to that.
    // this is referred to as "passing by reference"
    double tmp {b};
    b=a;
    a=tmp;
}

int main()
{
    double x {42.3};
    double y {11.2};

    std::cout << x << "\t" << y << "\n";

    swap(x,y);

    std::cout << x << "\t" << y << "\n";
    // in this case we first simply print x(42.3) and y(11.2)
    // then after applying the "swap function" (utilising references) 
    //we print them again to find the actual objects have been altered!
}