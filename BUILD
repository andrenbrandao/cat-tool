load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
  name = "ccat",
  srcs = ["ccat_main.cc"],
  data = ["testdata/test.txt", "testdata/test2.txt"],
  deps = [":ccat_lib"]
)

cc_library(
  name = "ccat_lib",
  srcs = ["ccat_lib.cc"],
  hdrs = ["ccat_lib.h"]
)

cc_test(
  name = "ccat_test",
  size = "small",
  srcs = ["ccat_test.cc"],
  deps = ["@com_google_googletest//:gtest_main", ":ccat_lib"],
)
