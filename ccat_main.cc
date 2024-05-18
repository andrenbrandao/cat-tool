#include "ccat_lib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  LineNumberConfig line_number_config = LineNumberConfig::Off;

  std::vector<std::string> filenames;

  for (int i = 1; i < argc; i++) {
    const std::string &arg = argv[i];
    if (arg == "-n") {
      line_number_config = LineNumberConfig::On;
    } else if (arg == "-b") {
      line_number_config = LineNumberConfig::NonBlankLinesOnly;
    } else {
      filenames.push_back(arg);
    }
  }

  if (filenames.empty()) {
    filenames.emplace_back("-");
  }

  for (const std::string &filename : filenames) {

    if (filename == "-") {
      PrintFile(std::cin, std::cout, line_number_config);
    } else {
      std::ifstream file{filename};
      if (!file) {
        std::cerr << "Could not open file " + filename << '\n';
        return 1;
      }
      PrintFile(file, std::cout, line_number_config);
    }
  }

  return 0;
}
