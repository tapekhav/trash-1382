#include "Logger/FileLog.h"

FileLog::FileLog(const std::string &file_name) {
    file.open(file_name);
}

FileLog::~FileLog() {
    file.close();
}

void FileLog::print(Message* msg) {
    file << msg;
}
