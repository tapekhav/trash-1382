#include "Log.h"
void Log::put_in_file(std::string message){
    if(out_file.is_open()){
        out_file << message<<std::endl;
    }
}
Log::Log(std::string file) : Log(){
    out_file = std::ofstream(file, std::ios::out);
}
Log::Log() : is_console_out_field_changes(false), is_console_out_player_changes(true), is_console_out_trigger_info(false), is_console_out_error(false){}
Log::~Log(){
    if(out_file.is_open()){
        out_file.close();
    }
}
void Log::set_is_console_out(bool console_out_field, bool console_out_player, bool console_out_trigger_info, bool console_out_error){
    is_console_out_field_changes = console_out_field;
    is_console_out_player_changes = console_out_player;
    is_console_out_trigger_info = console_out_trigger_info;
    is_console_out_error = console_out_error;
}
void Log::set_is_console_out_field_changes(bool console_out_field){
    is_console_out_field_changes = console_out_field;
}
void Log::set_is_console_out_player_changes(bool console_out_player){
    is_console_out_player_changes = console_out_player;
}
void Log::set_is_console_out_trigger_info(bool console_out_trigger_info){
    is_console_out_trigger_info = console_out_trigger_info;
}
void Log::set_is_console_out_error(bool console_out_error){
    is_console_out_error = console_out_error;
}
bool Log::get_is_console_out_field_changes(){
    return is_console_out_field_changes;
}
bool Log::get_is_console_out_player_changes(){
    return is_console_out_player_changes;
}
bool Log::get_is_console_out_trigger_info(){
    return is_console_out_trigger_info;
}
bool Log::get_is_console_out_error(){
    return is_console_out_error;
}
void Log::set_file_out(std::string file){
    //this->set_file_out(file_for_all, file_for_all, file_for_all, file_for_all);
    if(out_file.is_open()){
        out_file.close();
    }
    out_file = std::ofstream(file, std::ios::out);
}
void Log::put_field_changes(std::string message){
    this->put_in_file(message);
    if(is_console_out_field_changes){
        std::cout<<message<<std::endl;
    }
}
void Log::put_player_changes(std::string message){
    this->put_in_file(message);
    if(is_console_out_player_changes){
        std::cout<<message<<std::endl;
    }
}
void Log::put_trigger_info(std::string message){
    this->put_in_file(message);
    if(is_console_out_trigger_info){
        std::cout<<message<<std::endl;
    }
}
void Log::put_error(std::string message){
    this->put_in_file(message);
    if(is_console_out_error){
        std::cout<<message<<std::endl;
    }
}