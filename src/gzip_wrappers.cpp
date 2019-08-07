#include "gzip_wrappers.hpp"

using std::string;

// open gzip file
gzFile gzip_open(string const &filename, string const &mode) {
    return gzopen(filename.c_str(), mode.c_str());
}

// close gzip file
void gzip_close(gzFile &file, string const &filename) {
    gzclose(file);
};

/* GzipOutput */
GzipOutput::GzipOutput(string const &filename, size_t const compression_level) {
    size_t comp_level = compression_level;
    comp_level = std::min(comp_level, static_cast<unsigned long>(9));
    comp_level = std::max(comp_level, static_cast<unsigned long>(1));

    string fmode = fmt::format("wb{}", comp_level);
    filename_ = filename;
    fp_ = gzip_open(filename, fmode);
}

void GzipOutput::close() {
    this->flush();
    gzip_close(fp_, filename_);
}

void GzipOutput::write(string const &s) {
    write_queue_.push(s);
    if (write_queue_.size() > 128) {
        this->flush();
    }
}

void GzipOutput::flush() {
    std::stringstream buf;
    while (write_queue_.size() > 0) {
        buf << write_queue_.front();
        write_queue_.pop();
    }
    if (buf.str() != "") {
        gzputs(fp_, buf.str().c_str());
    }
}
