#include <iostream>

void swap( double& a, double& b)
{
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
}