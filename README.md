# Summary

Meraki provide the source code for u-boot for the MS225 upon request, however they do not provide the cross compilation toolchain.

The default make target will build a Ubuntu 14.04 build environment (GCC4) and then build u-boot according to the instructions from Meraki.

# Building

Run `make` and let Docker take care of the rest. At the end of the build you should have `U-boot.MS225/u-boot.bin`.
