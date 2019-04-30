#!/bin/bash
g++ -I../f2c/libf2c/x86/ -o test tstmvt.cpp mvtdstpack.cpp ../f2c/libf2c/x86/libf2c.a -lm && ./test
