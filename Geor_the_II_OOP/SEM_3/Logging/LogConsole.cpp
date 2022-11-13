#include "LogConsole.h"
void LogConsole::out_message(Message message){
    if(get_out_info(message.get_level())){
        Message pref_message = pref(message.get_level());
        if(pref_message.get_level() != none){
           std::cout << pref_message << std::endl; 
        }
        std::cout << message << std::endl;
    }
}