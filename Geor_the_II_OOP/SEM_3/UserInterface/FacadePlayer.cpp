#include "FacadePlayer.h"
FacadePlayer::FacadePlayer(Player *p, Field *f, Observer *o, CommandReader *r) : player(p), field(f), observer(o), reader(r){
    view = new FieldView;
};
GameStatus FacadePlayer::move_player(CommandOperand d){
    if(field->move_player(d)){
        GameStatus s = field->trigger_cell();
        observer->log_field_changes(field);
        observer->log_player_changes(player);
        return s;
    }
    observer->log_dead_end();
    return status_quo;
}
GameStatus FacadePlayer::game_start(){
    observer->log_start_game();
    observer->set_field(field);
    observer->set_player(player);
    GameStatus s;
    do{
        s = this->game_step();
    }
    while(s == status_quo);
    observer->log_finish_game(s);
    return s;
}
void FacadePlayer::player_menu(){
    CommandOperand op = reader->get_command();
    if(op == quit){
        return;
    }
    do{}while(game_start() == restart);
}
GameStatus FacadePlayer::game_step(){
    view->set_field(field);
    view->print();
    CommandOperand op = reader->get_command();
    switch(op){
        case play:
            return restart;
        case quit:
            return interrupt;
    }
    return this->move_player(op);
}
FacadePlayer::~FacadePlayer(){
    delete view;
}