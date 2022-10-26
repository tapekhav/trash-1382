#include "LoggerPool.h"

LoggerPool::LoggerPool(Logger *log) {}

LoggerPool::~LoggerPool() {
    //std::for_each(levels.begin(), levels.end(), [](LogLevel* lvl) {delete lvl;});
}

void LoggerPool::proceed(Message& msg) {

}

