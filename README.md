# cat-tool

cat - Unix Command line tool built for John Crickett's Coding Challenge.

## How to build and run

First, make sure you have [Bazel](https://bazel.build/install) installed.

```bash
bazel build :ccat
```

```bash
bazel run :ccat -- testdata/test.txt
```

To read from stdin:

```bash
head -n1 testdata/test.txt | ./bazel-bin/ccat -
```

Printing line numbers:

```bash
bazel run :ccat -- -n testdata/test.txt
```

## Running the tests

```bash
bazel test --test_output=all :ccat_test
```

## Resources

- [Bazel](https://bazel.build/) as the build tool.
- [Google Test](https://google.github.io/googletest/) for testing.
- [Bazel Compile Commands Extractor](https://github.com/hedronvision/bazel-compile-commands-extractor) to support autocompletion in Neovim and IDEs.
