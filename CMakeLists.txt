cmake_minimum_required(VERSION 3.0.0)
project(fastq-read-stats VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.56 REQUIRED COMPONENTS filesystem)
find_package(ZLIB)
add_executable(
    fastq-read-stats
    src/fastq_read_stats.cpp
    src/gzip_wrappers.cpp
    src/main.cpp
    src/options.cpp)
include_directories(include)
target_link_libraries(fastq-read-stats Boost::filesystem)
target_link_libraries(fastq-read-stats ${ZLIB_LIBRARIES})
install(TARGETS fastq-read-stats DESTINATION bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
