#include "ccat_lib.h"
#include <gtest/gtest.h>
#include <sstream>

// Tests printing of an input stream
TEST(PrintFileTest, OutputsLinesOfStream) {
  std::istringstream input_stream("hello\nthere");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, false, false);
  EXPECT_EQ(output_stream.str(), "hello\nthere\n");
}

TEST(PrintFileTest, PrintsLineNumbers) {
  std::istringstream input_stream("hello\nthere");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, true, true);
  EXPECT_EQ(output_stream.str(), "     1  hello\n     2  there\n");
}

TEST(PrintFileTest, PrintsLineNumbersOfBlankLines) {
  std::istringstream input_stream("hello\n\nthere\n\nagain");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, true, true);
  EXPECT_EQ(
      output_stream.str(),
      "     1  hello\n     2  \n     3  there\n     4  \n     5  again\n");
}

TEST(PrintFileTest, PrintsOnlyNonBlankLineNumbers) {
  std::istringstream input_stream("hello\n\nthere\n\nagain");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, true, false);
  EXPECT_EQ(output_stream.str(),
            "     1  hello\n\n     2  there\n\n     3  again\n");
}
