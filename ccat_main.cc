#include <fstream>
#include <iostream>
#include <string>

void PrintFile(std::istream &input_stream) {
  std::string strRead{};
  while (std::getline(input_stream, strRead)) {
    std::cout << strRead << '\n';
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Must add a filename" << std::endl;
    return 0;
  }
  const std::string &filename = argv[1];

  if (filename == "-") {
    PrintFile(std::cin);
  } else {
    std::ifstream file{filename};
    if (!file) {
      std::cerr << "Could not open file " + filename << std::endl;
      return 1;
    }
    PrintFile(file);
  }

  return 0;
}
