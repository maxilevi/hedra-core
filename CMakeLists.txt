project(hedracore C CXX)
cmake_minimum_required(VERSION 3.0)

set(MESHOPTIMIZER_SOURCES
    src/meshoptimizer/meshoptimizer.h
    src/meshoptimizer/allocator.cpp
    src/meshoptimizer/clusterizer.cpp
    src/meshoptimizer/indexcodec.cpp
    src/meshoptimizer/indexgenerator.cpp
    src/meshoptimizer/overdrawanalyzer.cpp
    src/meshoptimizer/overdrawoptimizer.cpp
    src/meshoptimizer/simplifier.cpp
    src/meshoptimizer/stripifier.cpp
    src/meshoptimizer/vcacheanalyzer.cpp
    src/meshoptimizer/vcacheoptimizer.cpp
    src/meshoptimizer/vertexcodec.cpp
    src/meshoptimizer/vfetchanalyzer.cpp
    src/meshoptimizer/vfetchoptimizer.cpp
)

set(FASTNOISE_SOURCES
    src/fastnoise-simd/FastNoiseSIMD.h
    src/fastnoise-simd/FastNoiseSIMD.cpp
    src/fastnoise-simd/FastNoiseSIMD_avx512.cpp
    src/fastnoise-simd/FastNoiseSIMD_sse2.cpp
    src/fastnoise-simd/FastNoiseSIMD_neon.cpp
    src/fastnoise-simd/FastNoiseSIMD_sse41.cpp
    src/fastnoise-simd/FastNoiseSIMD_internal.cpp
    src/fastnoise-simd/FastNoiseSIMD_internal.h
    src/fastnoise-simd/FastNoiseSIMD_avx2.cpp
)

set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_sse2.cpp PROPERTIES COMPILE_FLAGS /arch:SSE2)
set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_sse41.cpp PROPERTIES COMPILE_FLAGS /arch:SSE2)
set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx2.cpp PROPERTIES COMPILE_FLAGS /arch:AVX)
set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx512.cpp PROPERTIES COMPILE_FLAGS /arch:AVX)

add_library(noise_obj OBJECT ${FASTNOISE_SOURCES})
target_compile_options(noise_obj PRIVATE /GL-)

add_library(meshoptimizer_obj OBJECT ${MESHOPTIMIZER_SOURCES})
target_compile_options(meshoptimizer_obj PRIVATE /W4 /WX)

add_library(hedracore SHARED $<TARGET_OBJECTS:noise_obj> $<TARGET_OBJECTS:meshoptimizer_obj> src/hedra.h src/hedra.cpp)
target_include_directories(hedracore INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")

set_target_properties(hedracore PROPERTIES OUTPUT_NAME "hedracore")

if(MSVC)
	target_compile_options(hedracore PRIVATE /W4 /WX)
else()
	target_compile_options(hedracore PRIVATE -Wall -Wextra -Werror)
endif()
