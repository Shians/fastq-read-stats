#include "fastq_read_stats.hpp"

using std::string;
using std::vector;
using std::sort;
using std::accumulate;
using std::round;
using std::cout;
using std::ofstream;
using std::greater;

extern options_t PRG_OPTS;

void fastq_read_stats() {
    auto input_file = FastqFile(PRG_OPTS.input);

    vector<unsigned int> lengths;
    lengths.reserve(5000);

    FastqRecord fastq_read;
    while (1) {
        input_file.get_record(fastq_read);
        
        if (fastq_read.good) {
            lengths.push_back(fastq_read.seq.length());
        } else {
            break;
        }
    }

    if (PRG_OPTS.output != "") {
        ofstream output_file(PRG_OPTS.output);
        for (auto const& l : lengths) {
            output_file << l << "\n";
        }
    }

    sort(lengths.begin(), lengths.end(), greater<int>());

    unsigned long long int total = accumulate(lengths.begin(), lengths.end(), 0.0);
    double average = total/lengths.size();

    unsigned long long sum = 0;
    unsigned int N50 = 0;
    unsigned int N75 = 0;
    unsigned int N90 = 0;

    for (auto& l : lengths) {
        sum += l;
        if (N50 ==0 && sum > 0.5 * total) {
            N50 = l;
        }
        if (N75 ==0 && sum > 0.75 * total) {
            N75 = l;
        }
        if (N90 ==0 && sum > 0.9 * total) {
            N90 = l;
            break;
        }
    }

    cout << "file\treads\tbases\tmean\tmin\tQ1\tmedian\tQ3\tmax\tN50\tN75\tN90" << "\n";
    cout << PRG_OPTS.input << "\t"; // File
    cout << lengths.size() << "\t"; // Reads
    cout << total << "\t"; // Bases
    cout << round(average) << "\t"; // Mean
    cout << lengths[lengths.size() - 1] << "\t"; // Min
    cout << lengths[(3 * lengths.size())/4] << "\t"; // Q1
    cout << lengths[lengths.size()/2] << "\t"; // Median
    cout << lengths[lengths.size()/4] << "\t"; // Q3
    cout << lengths[0] << "\t"; // Max
    cout << N50 << "\t";
    cout << N75 << "\t";
    cout << N90 << "\t";
    cout << "\n";
}
