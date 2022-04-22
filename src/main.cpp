#include "main.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    parse_args(argc, argv);

    cout << "file\treads\tbases\tmean\tmin\tQ1\tmedian\tQ3\tmax\tN50\tN75\tN90" << "\n";
    for (auto& file : PRG_OPTS.inputs) {
        fastq_read_stats(file);
    }

    return 0;
}
