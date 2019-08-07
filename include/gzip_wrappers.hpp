#pragma once
#define FMT_HEADER_ONLY
#include "fmt/format.h"
#include "options.hpp"

#include <boost/filesystem.hpp>
#include <zlib.h>

#include <iostream>
#include <sstream>
#include <cstddef>
#include <string>
#include <numeric>
#include <limits>
#include <queue>
#include <mutex>
#include <algorithm>

gzFile gzip_open(std::string const &filename, std::string const &mode);
void gzip_close(gzFile file);

// class to represent a Gzip output file
struct GzipOutput {
    GzipOutput(std::string const &filename, size_t const compression_level);
    GzipOutput(std::string const &filename) : GzipOutput(filename, 4) {};

    void close();
    void write(std::string const &s);
    void flush();

private:
    gzFile fp_;
    std::string filename_;
    std::queue<std::string> write_queue_;
};
