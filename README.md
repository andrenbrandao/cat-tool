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
