#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Must add a filename" << std::endl;
    return 0;
  }
  const std::string &filename = argv[1];

  if (filename == "-") {
    std::string strRead{};
    while (std::getline(std::cin, strRead)) {
      std::cout << strRead << '\n';
    }
  } else {
    std::ifstream file{filename};
    if (!file) {
      std::cerr << "Could not open file " + filename << std::endl;
      return 1;
    }

    std::string strRead{};
    while (std::getline(file, strRead)) {
      std::cout << strRead << '\n';
    }
  }

  return 0;
}
