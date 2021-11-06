current_dir:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

.PHONY: all

target: all

docker-image:
	docker build -t ubuntu1404-crossarm -f Dockerfile .

docker-build:
	docker run -it --rm -v $(current_dir)/U-boot.MS225:/src -v $(current_dir)/build-uboot.sh:/tmp/build-uboot.sh ubuntu1404-crossarm /tmp/build-uboot.sh

docker-build-dbg:
	docker run -it --rm -v $(current_dir)/U-boot.MS225:/src -v $(current_dir)/build-uboot.sh:/tmp/build-uboot.sh --entrypoint=/bin/bash ubuntu1404-crossarm

all: docker-image docker-build

clean:
	docker run -it --rm -v $(current_dir)/U-boot.MS225:/src ubuntu1404-crossarm /bin/sh -c 'cd /src && make clean'
