This is only a test. Do not use in production.

## Install

1. Download and install the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) (emsdk).

2. Install [wabt](https://github.com/WebAssembly/wabt) if you want to be able to convert wasm files to wat (text format). Make sure to do `git clone --recursive` or it will not grab all of the required submodules. 

3. Activate emsdk: `source /path/to/emsdk_env.sh`

4. Compile with:

```bash
cd src/mvtdst
./compile.sh
```
