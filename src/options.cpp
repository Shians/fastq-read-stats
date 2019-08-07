#include "options.hpp"

options_t PRG_OPTS;

namespace fs = boost::filesystem;

void parse_args(int &argc, char *argv[]) {
    try {  
        TCLAP::CmdLine cmd("Command description message", ' ', "0.9.2");

        // arguments are pushed into order, so inserted from last to first
        string_arg input("", "i", "Fastq file", true, "", "gzipped fastq", cmd);

        cmd.parse(argc, argv);

        PRG_OPTS.input = input.getValue();
	} catch (TCLAP::ArgException &e) {
        throw e;
    }
}
