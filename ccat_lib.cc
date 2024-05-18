#include "ccat_lib.h"

constexpr int line_number_left_padding_length = 6;
constexpr int line_number_right_padding_length = 2;

void PrintLineNumber(std::ostream &output_stream, int line_number) {
  std::string line_number_str = std::to_string(line_number);
  for (long unsigned int i = 0;
       i < static_cast<long unsigned int>(line_number_left_padding_length) -
               line_number_str.length();
       i++) {
    output_stream << " ";
  }

  output_stream << line_number_str;

  for (int i = 0; i < line_number_right_padding_length; i++) {
    output_stream << " ";
  }
}

void PrintFile(std::istream &input_stream, std::ostream &output_stream,
               LineNumberConfig line_number_config) {
  int line_number = 1;

  std::string str_read{};
  while (std::getline(input_stream, str_read)) {
    if (str_read.length() == 0 &&
        line_number_config == LineNumberConfig::NonBlankLinesOnly) {
      output_stream << str_read << '\n';
      continue;
    }

    if (line_number_config != LineNumberConfig::Off) {
      PrintLineNumber(output_stream, line_number);
      line_number++;
    }

    output_stream << str_read << '\n';
  }
}
