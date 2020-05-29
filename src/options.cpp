#include "options.hpp"

options_t PRG_OPTS;

namespace fs = boost::filesystem;

void parse_args(int &argc, char *argv[]) {
    try {  
        TCLAP::CmdLine cmd("Command description message", ' ', "0.9.2");

        // arguments are pushed into order, so inserted from last to first
        ul_string_arg input("input", "Fastq file", true, "", "gzipped fastq", cmd);
        string_arg output("o", "output", "output length of each read into this file", false, "", "string", cmd);

        cmd.parse(argc, argv);

        PRG_OPTS.input = input.getValue();
        if (!boost::filesystem::exists(PRG_OPTS.input)) {
            throw std::runtime_error("input file does not exist.");
        }

        PRG_OPTS.output = output.getValue();
	} catch (TCLAP::ArgException &e) {
        throw e;
    }
}
