#ifndef CCAT_LIB_H
#define CCAT_LIB_H

#include <iostream>

void PrintFile(std::istream &input_stream, std::ostream &output_stream,
               bool print_line_numbers, bool number_blank_lines);

#endif // !CCAT_LIB_H
