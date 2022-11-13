#include "Log.h"
void Log::set_out_info(MessageLevel ml, bool b){
    out_info[ml] = b;
}
Message Log::pref(MessageLevel ml){
    if(current_level != ml){
        current_level = ml;
        switch(ml){
            case game_structs_change:
                return Message("GAME STRUCTS CHANGE:\n", ml);
            case game_status:
                return Message("GAME STATUS:\n", ml);
            case error:
                return Message("ERROR:\n", ml);
        }
    }
    return Message("", none);
}
bool Log::get_out_info(MessageLevel ml){
    if(out_info.begin() == out_info.end()){
        return true;
    }
    else if(out_info.find(ml) == out_info.end()){
        return false;
    }
    else{
        return out_info[ml];
    }
}