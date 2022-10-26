#include "EventFinal.h"
EventFinal::EventFinal(Player *p, int s, int e, int d, int a, EventCombatHard *b) : line_strangth(s), line_endurance(e), line_dexterity(d), line_armor(a), boss(b){
    player = p;
}
EventFinal::EventFinal(Player *p, int s, int e, int d, int a) : line_strangth(s), line_endurance(e), line_dexterity(d), line_armor(a), boss(nullptr){
    player = p;
}
EventFinal::EventFinal(Player *p) : line_strangth(1000), line_endurance(1000), line_dexterity(1000), line_armor(1000), boss(nullptr){
    player = p;
}
EventFinal::EventFinal(const EventFinal& e) : line_strangth(e.line_strangth), line_endurance(e.line_endurance), line_dexterity(e.line_dexterity), line_armor(e.line_armor), boss(e.boss){
    player = e.player;
}
EventFinal::EventFinal(EventFinal&& e){
    std::swap(player, e.player);
    std::swap(line_strangth, e.line_strangth);
    std::swap(line_endurance, e.line_endurance);
    std::swap(line_dexterity, e.line_dexterity);
    std::swap(line_armor, e.line_armor);
    std::swap(boss, e.boss);
}
EventFinal& EventFinal::operator=(const EventFinal& e){
    if(this != &e){
        player = e.player;
        line_strangth = e.line_strangth;
        line_endurance = e.line_endurance;
        line_dexterity = e.line_dexterity;
        line_armor = e.line_armor;
        boss = e.boss;
    }
    return *this;
}
EventFinal& EventFinal::operator=(EventFinal&& e){
    if(this != &e){
        std::swap(player, e.player);
        std::swap(line_strangth, e.line_strangth);
        std::swap(line_endurance, e.line_endurance);
        std::swap(line_dexterity, e.line_dexterity);
        std::swap(line_armor, e.line_armor);
        std::swap(boss, e.boss);
    }
    return *this;
}
GameStatus EventFinal::trigger(){
    if(line_strangth <= player->get_strength() && line_endurance <= player->get_endurance() && line_dexterity <= player->get_dexterity() && line_armor <= player->get_armor()){
        return win;
    }
    else{
        GameStatus status = boss->trigger();
        if(status == null_event){
            return status_quo;
        }
        return status;
    }
}
void EventFinal::set_line(int s, int e, int d, int a){
    line_strangth = s;
    line_endurance = e;
    line_dexterity = d;
    line_armor = s;
}
void EventFinal::set_line_strangth(int s){
    line_strangth = s;
}
void EventFinal::set_line_endurance(int e){
    line_endurance = e;
}
void EventFinal::set_line_dexterity(int d){
    line_dexterity = d;
}
void EventFinal::set_line_armor(int a){
    line_armor = a;
}
void EventFinal::set_boss(EventCombatHard *b){
    boss = b;
}
int EventFinal::get_line_strangth(){
    return line_strangth;
}
int EventFinal::get_line_endurance(){
    return line_endurance;
}
int EventFinal::get_line_dexterity(){
    return line_dexterity;
}
int EventFinal::get_line_armor(){
    return line_armor;
}
EventCombatHard *EventFinal::get_boss(){
    return boss;
}