#include "FacadePlayer.h"
FacadePlayer::FacadePlayer(Player *p, Field *f, Observer *o) : player(p), field(f), observer(o){
    view = new FieldView;
};
GameStatus FacadePlayer::move_player(Direction d){
    if(field == nullptr){
        throw("Error! FacadePlayer class object does not have a field set.\n");
    }
    if(field->move_player(d)){
        observer->log_trigger_info(field);
        GameStatus s = field->trigger_cell();
        observer->log_field_changes(field);
        observer->log_player_changes(player);
        return s;
    }
    observer->log_dead_end();
    return status_quo;
}
GameStatus FacadePlayer::game_start(){
    observer->set_field(field);
    observer->set_player(player);
    GameStatus s;
    do{
        s = this->game_step();
    }
    while(s == status_quo);
    return s;
}
GameStatus FacadePlayer::game_step(){
    view->set_field(field);
    view->print();
    GameStatus s = this->move_player(CommandReader().get_direction());
    return s;
}
FacadePlayer::~FacadePlayer(){
    delete view;
}