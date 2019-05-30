#!/bin/bash
set -euxo pipefail
IFS=$'\n\t'

# Compile fortran to C
#../f2c/f2c/f2c -C++ mvtdstpack.f
#mv mvtdstpack.c mvtdstpack.cpp

# Activate paths for emscripten
#source /path/to/emsdk/emsdk_env.sh
if [[ -z "${EMSDK}" ]]; then
  echo "Activate emsdk before running"
  exit 1
fi

# Compile to WASM
# Having a .html extension on the -o file makes emscripten generate .js, .html, and .wasm
# Other interesting options: 
# -s SINGLE_FILE=1 apparently tries to put everything into the same file (JS + WASM)
# -s EXPORT_ES6=1 tries to export in ES6 mode with an export statement
rm -rf wasm
mkdir -p wasm
em++ --bind -std=c++11 -Os \
  -I../f2c/libf2c/llvm/emscripten \
  -s WASM=1 \
  -s MODULARIZE=1 \
  -s EXPORT_NAME="'mvtdstpack'" \
  -o wasm/mvtdstpack.js \
  mvtdstpack.cpp mvtdst.cpp ../f2c/libf2c/llvm/emscripten/libf2c.a -lm

rm -rf asm
mkdir -p asm
em++ --bind -std=c++11 -Os \
  -I../f2c/libf2c/llvm/emscripten \
  -s WASM=0 \
  -s MODULARIZE=1 \
  -s EXPORT_ES6=1 \
  --memory-init-file 0 \
  -s EXPORT_NAME="'mvtdstpack'" \
  -o asm/mvtdstpack.js \
  mvtdstpack.cpp mvtdst.cpp ../f2c/libf2c/llvm/emscripten/libf2c.a -lm

# This command line is useful for compiling with debug support. It also generates source code maps.
#em++ --bind -std=c++11 -g4 -I../f2c/libf2c/llvm/emscripten -s WASM=1 -s ASSERTIONS=2 -s DEMANGLE_SUPPORT=1 -o mvtdstpack.html mvtdstpack.cpp pmvnorm.cpp ../f2c/libf2c/llvm/emscripten/libf2c.a -lm

# Convert wasm to text format to see output
# Must have installed wabt: https://github.com/WebAssembly/wabt
if which wasm2wat; then
  wasm2wat wasm/mvtdstpack.wasm -o wasm/mvtdstpack.wat
fi
