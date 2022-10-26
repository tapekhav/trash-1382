#pragma once
#include <fstream>
#include <iostream>
#include <string.h>
class Log{
    private:
        std::ofstream out_file;
        bool is_console_out_field_changes;
        bool is_console_out_player_changes;
        bool is_console_out_trigger_info;
        bool is_console_out_error;
        void put_in_file(std::string message);
    public:
        Log(std::string file);
        Log();
        ~Log();
        void set_is_console_out(bool console_out_field, bool console_out_player, bool console_out_trigger_info, bool console_out_error);
        void set_is_console_out_field_changes(bool console_out_field);
        void set_is_console_out_player_changes(bool console_out_player);
        void set_is_console_out_trigger_info(bool console_out_trigger_info);
        void set_is_console_out_error(bool console_out_error);
        bool get_is_console_out_field_changes();
        bool get_is_console_out_player_changes();
        bool get_is_console_out_trigger_info();
        bool get_is_console_out_error();
        void set_file_out(std::string file);
        void put_field_changes(std::string message);
        void put_player_changes(std::string message);
        void put_trigger_info(std::string message);
        void put_error(std::string message);
};