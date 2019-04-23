#!/bin/bash
mkdir f2c
cd f2c
curl -O https://www.netlib.org/f2c/src.tgz
tar xf src.tgz --strip-components 1
cd ..

mkdir libf2c
cd libf2c
curl -O https://www.netlib.org/f2c/libf2c.zip
unzip libf2c.zip
cd ..
