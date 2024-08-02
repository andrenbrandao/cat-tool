load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
  name = "ccat",
  srcs = ["ccat_main.cc"],
  data = ["testdata/test.txt", "testdata/test2.txt"],
  deps = [":ccat_lib", "@abseil-cpp//absl/flags:flag", "@abseil-cpp//absl/flags:parse"]
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

sh_test(
    name = "ccat_integration_test",
    size = "small",
    srcs = ["main_test.sh"],
    data = [
      "testdata/test.txt",
      ":ccat"
    ],
    args = [
      '$(location :testdata/test.txt)',
      '$(location :ccat)',
    ],
)
