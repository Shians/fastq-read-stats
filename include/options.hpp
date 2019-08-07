#pragma once
#include <algorithm>
#include <boost/filesystem.hpp>
#include <string>
#include <tclap/CmdLine.h>

struct options_t {
    std::string input;
};

extern options_t PRG_OPTS;

typedef TCLAP::ValueArg<std::string> string_arg;
typedef TCLAP::ValueArg<int> int_arg;
typedef TCLAP::SwitchArg switch_arg;

void parse_args(int &argc, char *argv[]);
