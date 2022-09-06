# Fastq Read Stats

Reports a summary of the read lengths in fastq(.gz) files with the format below

```
> fastq-read-stats reads.fastq.gz
reading from reads.fastq.gz
Read length summary:

Reads processed: 71915

  Mean: 566

   Min: 55
    Q1: 399
Median: 508
    Q3: 671
   Max: 4280
```

# Installation

```bash
git clone https://github.com/Shians/fastq-read-stats.git
cd fastq-read-stats
cmake .
make
make install
# To install to custom path 
# make DESTDIR=/custom/path install
```

# License

This software is licensed under the APL-2 license.
