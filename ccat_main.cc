#include "ccat_lib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  LineNumberConfig line_number_config = LineNumberConfig::Off;

  std::vector<std::string> filenames;

  for (int i = 1; i < argc; i++) {
    const std::string &sv = argv[i];
    if (sv == "-n") {
      line_number_config = LineNumberConfig::On;
    } else if (sv == "-b") {
      line_number_config = LineNumberConfig::NonBlankLinesOnly;
    } else {
      filenames.push_back(sv);
    }
  }

  if (filenames.size() == 0) {
    filenames.push_back("-");
  }

  for (const std::string &filename : filenames) {

    if (filename == "-") {
      PrintFile(std::cin, std::cout, line_number_config);
    } else {
      std::ifstream file{filename};
      if (!file) {
        std::cerr << "Could not open file " + filename << std::endl;
        return 1;
      }
      PrintFile(file, std::cout, line_number_config);
    }
  }

  return 0;
}
