#include "SetSetting.h"
void SetSetting::set_log(Log *log){
    std::string levels;
    std::cin >> levels;
    for(char i: levels){
        switch(i){
            case '0':
                log->set_out_info(game_structs_change, false);
                log->set_out_info(game_status, false);
                log->set_out_info(error, false);
                break;
            case '1':
                log->set_out_info(game_structs_change, true);
                break;
            case '2':
                log->set_out_info(game_status, true);
                break;
            case '3':
                log->set_out_info(error, true);
                break;
            default:
                break;
        }
    }
}