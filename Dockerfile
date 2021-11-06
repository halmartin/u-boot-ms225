FROM ubuntu:14.04

RUN apt-get update && apt-get install -y --no-install-recommends \
  perl binutils make build-essential flex bison ncurses-dev \
  gcc-arm-linux-gnueabihf binutils-arm-linux-gnueabihf bc

WORKDIR /src

