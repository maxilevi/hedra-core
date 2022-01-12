project(hedracore C CXX)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE RELEASE)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "-fPIC")
endif()

set(MESHOPTIMIZER_SOURCES
    src/export.h
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

if(MSVC)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_sse2.cpp PROPERTIES COMPILE_FLAGS /arch:SSE2)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_sse41.cpp PROPERTIES COMPILE_FLAGS /arch:SSE2)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx2.cpp PROPERTIES COMPILE_FLAGS /arch:AVX)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx512.cpp PROPERTIES COMPILE_FLAGS /arch:AVX)
else()
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_sse2.cpp PROPERTIES COMPILE_FLAGS -msse2)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_sse41.cpp PROPERTIES COMPILE_FLAGS -msse4.1)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx2.cpp PROPERTIES COMPILE_FLAGS -mavx2)
	#set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx2.cpp PROPERTIES COMPILE_FLAGS -march=native)
	set_source_files_properties(src/fastnoise-simd/FastNoiseSIMD_avx512.cpp PROPERTIES COMPILE_FLAGS -mavx512f)
endif()

add_library(noise_obj OBJECT ${FASTNOISE_SOURCES})
if(MSVC)
	target_compile_options(noise_obj PRIVATE /GL- /MT)
else()
	target_compile_options(noise_obj PRIVATE -shared -std=c++11)
endif()

add_library(meshoptimizer_obj OBJECT ${MESHOPTIMIZER_SOURCES})
if(MSVC)
	target_compile_options(meshoptimizer_obj PRIVATE /W4 /WX /MT)
else()
	target_compile_options(meshoptimizer_obj PRIVATE -shared -std=c++11)
endif()

add_library(hedracore SHARED $<TARGET_OBJECTS:noise_obj> $<TARGET_OBJECTS:meshoptimizer_obj> src/hedra.h src/export.h src/hedra.cpp src/vectormath.h src/meshing/marchingcubes.cpp src/meshing/marchingcubes.h src/meshing/tables.h src/meshing/vertexData.h src/meshing/mesher.cpp src/meshing/mesher.h src/meshing/painter.cpp src/meshing/painter.h src/meshing/block.h src/mathf.h src/meshing/blocktype.h)
target_include_directories(hedracore INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")

set_target_properties(hedracore PROPERTIES OUTPUT_NAME "hedracore")

if(MSVC)
	target_compile_options(hedracore PRIVATE /MT)
else()
	target_compile_options(hedracore PRIVATE -shared)
endif()
