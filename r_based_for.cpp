#include <iostream>
#include <vector>
#include <string>

int main()
{   std::vector<int> my_ints = {1,2,3};

    for (const int& element : my_ints) {
    std::cout << element << "\n";
    }
    for (int& element : my_ints){
    ++element;
    }
    for (const int& element : my_ints){
    std::cout << element << "\n";
    }
}