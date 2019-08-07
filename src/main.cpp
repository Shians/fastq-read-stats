#include "main.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    parse_args(argc, argv);

    fastq_read_stats();

    return 0;
}
