#ifndef MPAGSCIPHER_TRANSFORMCHAR_HPP
#define MPAGSCIPHER_TRANSFORMCHAR_HPP

#include <string>

// This is a header file where we can write the declaration of the function

// We can 'declare' a function without including the body
// i.e. we omit the implementation or 'definition' of the function
// This tells the compiler that the function does indeed exist but promises 
// its definition will be found somewhere else:
// Think that the arguments must be the same in the declaration here and in the definition elsewhere
std::string transformChar(const char in_char);

#endif //MPAGSCIPHER_TRANSFORMCHAR_HPP