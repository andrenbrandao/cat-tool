#include <fstream>
#include <iostream>
#include <string>
#include <vector>

constexpr int line_number_left_padding_length = 6;
constexpr int line_number_right_padding_length = 2;

void PrintLineNumber(int line_number) {
  int line_number_str_length = line_number / 10 + 1;
  for (int i = 0; i < line_number_left_padding_length - line_number_str_length;
       i++) {
    std::cout << " ";
  }

  std::cout << line_number;

  for (int i = 0; i < line_number_right_padding_length; i++) {
    std::cout << " ";
  }
}

void PrintFile(std::istream &input_stream, bool print_line_numbers) {
  int line_number = 1;

  std::string str_read{};
  while (std::getline(input_stream, str_read)) {
    if (print_line_numbers) {
      PrintLineNumber(line_number);
      line_number++;
    }

    std::cout << str_read << '\n';
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Must add a filename" << std::endl;
    return 0;
  }

  std::vector<std::string> filenames;
  bool print_line_numbers = false;

  for (int i = 1; i < argc; i++) {
    const std::string &sv = argv[i];
    if (sv == "-n") {
      print_line_numbers = true;
    } else {
      filenames.push_back(sv);
    }
  }

  for (const std::string &filename : filenames) {

    if (filename == "-") {
      PrintFile(std::cin, print_line_numbers);
    } else {
      std::ifstream file{filename};
      if (!file) {
        std::cerr << "Could not open file " + filename << std::endl;
        return 1;
      }
      PrintFile(file, print_line_numbers);
    }
  }

  return 0;
}
