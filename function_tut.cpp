#include <iostream>
// this function multiplies two numbers together
double multiply( const double first, const double second )
{
    return first * second;
}
//this function prints out the argument
void print( const double value )
{std::cout<< "Result: "<< value << std::endl;
}
int main() /* main function is special function that is where the program starts, but behaves in the same way*/
{
    double a{43.0};
    double b{21.0};
    
    double c{ multiply(a,b)};
    print(c);

    print(multiply(a,c));
}