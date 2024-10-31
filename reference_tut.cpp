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

void print(const double& a, const double& b)
{// here we have const references where the objects are referred to with "&"" 
//but we specify we don't want to alter them through "const"
    std::cout << a <<"\t" << b << "\n";
}

int main()
{
    double x {42.3};
    double y {11.2};

    print(x,y);
    swap(x,y);
    print(x,y); 
}