#include "ccat_lib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

ABSL_FLAG(bool, n, false, "number all output lines");
ABSL_FLAG(bool, b, false, "number nonempty outputlines, overrides -n");

int main(int argc, char *argv[]) {
  absl::ParseCommandLine(argc, argv);
  LineNumberConfig line_number_config = LineNumberConfig::Off;

  if (absl::GetFlag(FLAGS_b)) {
    line_number_config = LineNumberConfig::NonBlankLinesOnly;
  } else if (absl::GetFlag(FLAGS_n)) {
    line_number_config = LineNumberConfig::On;
  }

  std::vector<std::string> filenames;

  for (int i = 1; i < argc; i++) {
    const std::string &arg = argv[i];
    if (arg[0] != '-') {
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
