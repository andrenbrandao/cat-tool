#include "ccat_lib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  bool print_line_numbers = false;
  bool number_blank_lines = true;

  std::vector<std::string> filenames;

  for (int i = 1; i < argc; i++) {
    const std::string &sv = argv[i];
    if (sv == "-n") {
      print_line_numbers = true;
    } else if (sv == "-b") {
      number_blank_lines = false;
      print_line_numbers = true;
    } else {
      filenames.push_back(sv);
    }
  }

  if (filenames.size() == 0) {
    filenames.push_back("-");
  }

  for (const std::string &filename : filenames) {

    if (filename == "-") {
      PrintFile(std::cin, std::cout, print_line_numbers, number_blank_lines);
    } else {
      std::ifstream file{filename};
      if (!file) {
        std::cerr << "Could not open file " + filename << std::endl;
        return 1;
      }
      PrintFile(file, std::cout, print_line_numbers, number_blank_lines);
    }
  }

  return 0;
}
