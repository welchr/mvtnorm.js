#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

# Compile fortran to C
#../f2c/f2c/f2c -C++ mvtdstpack.f
#mv mvtdstpack.c mvtdstpack.cpp

# Activate paths for emscripten
source /Users/welchr/scratch/emsdk/emsdk_env.sh

# Compile to WASM
# Having a .html extension on the -o file makes emscripten generate .js, .html, and .wasm
#em++ --bind -std=c++11 -O3 -I../f2c/test/emscripten -s WASM=1 -s NO_EXIT_RUNTIME=1 -s SIDE_MODULE=1 -o mvtdstpack.wasm mvtdstpack.cpp pmvnorm.cpp ../f2c/test/libf2c.a -lm
em++ --bind -std=c++11 -g4 -I../f2c/libf2c/emscripten -s WASM=1 -s ASSERTIONS=2 -s DEMANGLE_SUPPORT=1 -o mvtdstpack.html mvtdstpack.cpp pmvnorm.cpp ../f2c/libf2c/emscripten/libf2c.a -lm

# Convert wasm to text format to see output
/Users/welchr/scratch/wabt/build/wasm2wat mvtdstpack.wasm -o mvtdstpack.wat
