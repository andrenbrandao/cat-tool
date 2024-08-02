#include "ccat_lib.h"
#include <gtest/gtest.h>
#include <sstream>

// Tests printing of an input stream
TEST(PrintFileTest, OutputsLinesOfStream) {
  std::istringstream input_stream("hello\nthere");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream);
  EXPECT_EQ(output_stream.str(), "hello\nthere\n");
}

TEST(PrintFileTest, PrintsLineNumbers) {
  std::istringstream input_stream("hello\nthere");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, LineNumberConfig::On);
  EXPECT_EQ(output_stream.str(), "     1\thello\n     2\tthere\n");
}

TEST(PrintFileTest, PrintsLineNumbersOfBlankLines) {
  std::istringstream input_stream("hello\n\nthere\n\nagain");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, LineNumberConfig::On);
  EXPECT_EQ(
      output_stream.str(),
      "     1\thello\n     2\t\n     3\tthere\n     4\t\n     5\tagain\n");
}

TEST(PrintFileTest, PrintsNonBlankLineNumbersOnly) {
  std::istringstream input_stream("hello\n\nthere\n\nagain");
  std::ostringstream output_stream{};
  PrintFile(input_stream, output_stream, LineNumberConfig::NonBlankLinesOnly);
  EXPECT_EQ(output_stream.str(),
            "     1\thello\n\n     2\tthere\n\n     3\tagain\n");
}
