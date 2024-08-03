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

Printing line numbers only on non blank lines:

```bash
sed G testdata/test.txt | ./bazel-bin/ccat -b
```

## Running the tests

```bash
bazel test --test_output=all :all
```

## Autocomplete with Neovim

Because we are using Bazel, `clangd` autocomplete in Neovim doesn't know where to find the headers. To fix it, I'm using [Hedron's Compile Commands Extractor for Bazel](https://github.com/hedronvision/bazel-compile-commands-extractor).

Execute the following command to fix autocomplete when new dependencies are installed:

```
bazel run @hedron_compile_commands//:refresh_all --noincompatible_sandbox_hermetic_tmp
```

## Resources

- [Bazel](https://bazel.build/) as the build tool.
- [Google Test](https://google.github.io/googletest/) for testing.
- [Bazel Compile Commands Extractor](https://github.com/hedronvision/bazel-compile-commands-extractor) to support autocompletion in Neovim and IDEs.
