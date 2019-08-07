#include "fastq_read_stats.hpp"

using std::string;
using std::vector;
using std::sort;
using std::accumulate;
using std::round;
using std::cout;

extern options_t PRG_OPTS;

void fastq_read_stats() {
    auto input_file = FastqFile(PRG_OPTS.input);

    vector<int> lengths;
    lengths.reserve(5000);

    FastqRecord fastq_read;
    while (1) {
        fastq_read = input_file.get_record();
        
        if (fastq_read.good) {
            lengths.push_back(fastq_read.seq.length());
        } else {
            break;
        }
    }

    sort(lengths.begin(), lengths.end());

    double average = accumulate(lengths.begin(), lengths.end(), 0.0)/lengths.size();

    cout << "Read length summary: \n\n";
    cout << "Reads processed: " << lengths.size() << "\n\n";
    cout << "  Mean: " << round(average) << "\n\n";
    cout << "   Min: " << lengths[0] << "\n";
    cout << "    Q1: " << lengths[lengths.size()/4] << "\n";
    cout << "Median: " << lengths[lengths.size()/2] << "\n";
    cout << "    Q3: " << lengths[(3 * lengths.size())/4] << "\n";
    cout << "   Max: " << lengths[lengths.size() - 1] << "\n";

}
