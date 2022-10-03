APP_CC := arm-buildroot-linux-gnueabihf-gcc

SRC_DIR := ${PWD}/src
INC_DIR := ${PWD}/include
LIB_DIR := ${PWD}/lib
OUT_DIR := ${PWD}/out

TEST_SRC_DIR := ${SRC_DIR}/test

COMPILE_FLAG := -I ${INC_DIR}

test_jpg:${TEST_SRC_DIR}/test_jpg.c ${TEST_SRC_DIR}/display.c ${LIB_DIR}/libjpeg.a
	@${APP_CC} ${COMPILE_FLAG} $^ -o ${OUT_DIR}/$@

all:test_jpg


clean:
	@rm -rf ${OUT_DIR}/*
