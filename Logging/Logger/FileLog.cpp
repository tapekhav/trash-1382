#include "Logger/FileLog.h"

FileLog::FileLog(const std::string &file_name) {
    file.open(file_name, std::ios::app);
}

FileLog::~FileLog() {
    file.close();
}

void FileLog::print(Message& msg) {
    msg.update();
    file << msg;
}
