#!/bin/sh

export CROSS_COMPILE=arm-linux-gnueabihf-
cd /src && make brumby_config && make
