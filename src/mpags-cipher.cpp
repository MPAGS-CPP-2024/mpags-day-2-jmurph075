#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream> // to handle I-O files

#include "TransformChar.hpp"
#include "processCommandLine.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    //const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    // We now want to process the command line arguments
    // We pass the arguments into the function we've seperately defined to process them
    const bool cmdLineStatus{processCommandLine(
        cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile)};

    // Any failure in the argument procesing means we can't continue
    // Use a non-zero reutrn value to indicate failure
    // "!" means "not-" so if cmdLineStatus not true (something wrong) we return 1
    if (!cmdLineStatus){
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    //if the inputfile argument is NOT empty
    if (!inputFile.empty()) {
        //open the file and attempt to read from it
        std::ifstream inputStream{inputFile};
        if (!inputStream.good()){
            //raise an error if not readable
            std::cerr << "[error] failed to create istream on file '"
                      << inputFile << "'" <<std::endl;
            return 1;
        }

        //if readable, loop over each character from the file
        // pass it to the transform char function
        while (inputStream >> inputChar){
            inputText += transformChar(inputChar);
        }

    } else{
        // if no input file, then we simply loop over character
        // from user input (until Ctrl-D pressed).
        while (std::cin >> inputChar){
            inputText += transformChar(inputChar);
        }
    }

    //Output the transliterated text to stdout/file

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        //open the output file and check that we can write to it
        std::ofstream outputStream{outputFile};
        if (!outputStream.good()){
            //raise an error if not writable
            std::cerr << "[error] failed to create ostream on file '"
                      << outputFile << "'" <<std::endl;
            return 1;
        }
        
        //if writable, print the transliterated text to the file
        outputStream << inputText << std::endl;
    
    } else{
        //if no output file provided, just print the transliterated text to the screen
        std::cout << inputText << std::endl;
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}


