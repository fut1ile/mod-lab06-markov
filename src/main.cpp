#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "textgen.h"

int main(int argc, char* argv[]) {
  try {
    std::string inputFile = "input.txt";
    std::string outputFile = "result/gen.txt";
    int prefixSize = 2;
    int maxWords = 1000;

    if (argc > 1) {
      inputFile = argv[1];
    }

    if (argc > 2) {
      maxWords = std::stoi(argv[2]);
    }

    MarkovTextGenerator generator(prefixSize);

    std::cout << "Building model from " << inputFile << "..." << std::endl;
    generator.buildFromFile(inputFile);

    std::cout << "Generating " << maxWords << " words..." << std::endl;
    std::string generated = generator.generate(maxWords);

    std::ofstream out(outputFile);
    out << generated;
    out.close();

    std::cout << "Generated text saved to " << outputFile << std::endl;
    std::cout << "\n--- Preview ---\n";

    size_t previewSize = std::min<size_t>(500, generated.size());
    std::cout << generated.substr(0, previewSize) << "...\n";
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
