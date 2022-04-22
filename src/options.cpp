#include "options.hpp"

options_t PRG_OPTS;

namespace fs = boost::filesystem;

void parse_args(int &argc, char *argv[]) {
    try {  
        TCLAP::CmdLine cmd("Command description message", ' ', "0.9.3");

        // arguments are pushed into order, so inserted from last to first
        ul_multi_arg inputs("inputs", "Fastq file", true, "file names", cmd);

        cmd.parse(argc, argv);

        PRG_OPTS.inputs = inputs.getValue();
        for (auto& f : PRG_OPTS.inputs) {
            if (!boost::filesystem::exists(f)) {
                throw std::runtime_error("at least one input file does not exist.");
            }
        }
	} catch (TCLAP::ArgException &e) {
        throw e;
    }
}
