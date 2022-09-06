# Fastq Read Stats

Reports a summary of the read lengths in fastq(.gz) files with the format below

```
> fastq-read-stats test1.fq.gz test2.fq.gz
file	reads	bases	mean	min	Q1	median	Q3	max	N50	N75	N90
test1.fq.gz	10000	56447874	5644	179	1073	2726	6907	75470	12557	5598	2591
test2.fq.gz	10000	78005682	7800	141	1695	4456	11136	87166	14921	8190	3849
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
