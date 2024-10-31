#ifndef MPAGSCIPHER_PROCESSCOMMANLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANLINE_HPP
#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& cmdLineArgs, 
bool& helpRequested, bool& versionRequested, std::string& inputFile, std::string& outputFile);

#endif //MPAGSCIPHER_PROCESSCOMMANLINE_HPP