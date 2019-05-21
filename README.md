This is only a test. Do not use in production.

## Install

1. Install clang on your system. On Mac it should already be installed. For Ubuntu, you can do `sudo apt-get install clang`.

1. Download and install the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) (emsdk).

2. Install [wabt](https://github.com/WebAssembly/wabt) if you want to be able to convert wasm files to wat (text format). Make sure to do `git clone --recursive` or it will not grab all of the required submodules.

3. Activate emsdk: `source /path/to/emsdk_env.sh`

4. Compile libf2c:

```bash
cd src/f2c/libf2c/llvm
make
```

If your system clang (not the clang bundled with emsdk) is not located at `/usr/bin/clang`, modify the `SYSTEM_CLANG` variable in the Makefile.

5. Compile wasm/asm.js:

```bash
cd src/mvtdst
./compile.sh
```
