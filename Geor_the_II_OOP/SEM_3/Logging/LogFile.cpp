#include "LogFile.h"
LogFile::LogFile(std::string file_name) : out(std::ofstream(file_name, std::ios_base::out | std::ios_base::app)){}
void LogFile::out_message(Message message){
    if(out.is_open() && this->get_out_info(message.get_level())){
        Message pref_message = pref(message.get_level());
        if(pref_message.get_level() != none){
           out << pref_message << std::endl; 
        }
        out << message << std::endl;
    }
}
LogFile::~LogFile(){
    if(out.is_open()){
        out.close();
    }
}