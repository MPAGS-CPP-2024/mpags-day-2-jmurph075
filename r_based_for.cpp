#include <iostream>
#include <vector>
#include <string>

int main()
{   std::vector<int> my_ints = {1,2,3};

    for (const int& element : my_ints) {
        //here we declare the elements in the vectors as constant within the for loop
    std::cout << element << "\n";
    //so they just print as we'd expect
    }
    for (int& element : my_ints){
    ++element; // ++ just means increase by 1 increment, equivalent to +=1 in Python.
    //here we say that we can change the values within my_ints by referencing with &
    }
    for (const int& element : my_ints){
    std::cout << element << "\n";
    //so when we go and print them out again, they have been increments by 1
    // i.e 2,3,4
    }
}