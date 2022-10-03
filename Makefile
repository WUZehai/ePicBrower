APP_CC := arm-buildroot-linux-gnueabihf-gcc

SRC_DIR := ${PWD}/src

INC_DIR := ${PWD}/include
INC_DISPLAY_DIR := ${INC_DIR}/display
INC_RENDER_DIR := ${INC_DIR}/render

LIB_DIR := ${PWD}/lib
OUT_DIR := ${PWD}/out

TEST_SRC_DIR := ${SRC_DIR}/test

COMPILE_FLAG := -I${INC_DIR} -I${INC_DISPLAY_DIR} -I${INC_RENDER_DIR}

ePicBrower:${SRC_DIR}/*.c ${SRC_DIR}/display/*.c ${SRC_DIR}/render/*.c ${SRC_DIR}/render/operation/*.c
	@${APP_CC} ${COMPILE_FLAG} $^ -o ${OUT_DIR}/$@

test_jpg:${TEST_SRC_DIR}/test_jpg.c ${TEST_SRC_DIR}/display.c ${LIB_DIR}/libjpeg.a
	@${APP_CC} ${COMPILE_FLAG} $^ -o ${OUT_DIR}/$@

all:ePicBrower test_jpg


clean:
	@rm -rf ${OUT_DIR}/*
