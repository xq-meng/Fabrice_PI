cmake_minimum_required (VERSION 3.10)
project (Fabrice_PI)
set (SOURCES 
	src/Fabrice_PI.cpp
	src/main.cpp
    )

# openMP required
find_package (OpenMP REQUIRED)
if (OPENMP_FOUND)
message ("OPENMP FOUND")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories (${PROJECT_SOURCE_DIR}/src)
add_executable (${CMAKE_PROJECT_NAME} ${SOURCES})
