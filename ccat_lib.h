#ifndef CCAT_LIB_H
#define CCAT_LIB_H

#include <iostream>

enum class LineNumberConfig {
  Off,
  On,
  NonBlankLinesOnly,
};

void PrintFile(std::istream &input_stream, std::ostream &output_stream,
               LineNumberConfig line_number_config = LineNumberConfig::Off);

#endif // !CCAT_LIB_H
