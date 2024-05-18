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
