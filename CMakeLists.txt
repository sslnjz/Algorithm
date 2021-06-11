cmake_minimum_required(VERSION 3.14)
project(Algorithm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(${PROJECT_SOURCE_DIR}/Leetcode)

set(SRCs
	"Leetcode/tree.h"
	"Leetcode/twosum.h"
	"algorithm.h"
	"list.h"
	"utility.h"
	"main.cpp"
)

add_executable(Algorithm ${SRCs})