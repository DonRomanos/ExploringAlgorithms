[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build](https://github.com/DonRomanos/ExploringAlgorithms/actions/workflows/build.yaml/badge.svg?branch=master)](https://github.com/DonRomanos/ExploringAlgorithms/actions/workflows/build.yaml)

# Exploring Algorithms

This provides a simple playground for playing around with different algorithms. I use this to learn about algorithms and prepare for some interviews.

## Setup

Requirements:

* CMake
* Conan
* Python (for Conan)

Conan is tightly integrated into cmake and will be automatically called by it

```shell
mkdir build && cd build
cmake -G ...
cmake --build ..
ctest
```

Now you should see the library successfully compiling and running the tests.

### Disabling some of the Dependencies

If you don't have the dependencies or dont want to build with them for some reason you can disable them with these CMake Options, simply set them to 'OFF'.

```cmake
BUILD_TESTS
BUILD_BENCHMARK
```