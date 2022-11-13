#include <iostream>
#include "../UserInterface/FacadePlayer.h"
#include "../Events/EventCasing.h"
#include "../Events/FieldEvents/EventMakeBorder.h"
#include "../Events/PlayerEvents/EventBonus.h"
#include "../Events/PlayerEvents/EventFinal.h"
#include "../Logging/LogFile.h"
#include "../Logging/LogConsole.h"
#include "../CommandReader/CommandReaderKeyboard.h"
#include "../CommandReader/SetSetting.h"
int main(){
    Field f(10, 10);
    f.get_cell(1, 1)->set_passable(false);
    Player p(100, 20, 20, 20, 20, 200);
    LogFile logf("Text.txt");
    CommandReaderKeyboard rc("CommandFile.txt");
    SetSetting().set_log(&logf);
    LogConsole logc;
    SetSetting().set_log(&logc);
    Observer o(&logf);
    o.add_log(&logc);
    FacadePlayer fa(&p, &f, &o, &rc);
    EventBonus eb(&p);
    EventCasing ceb(&eb, 0.08);
    EventMakeBorder emb(&f);
    EventCasing cemb(&emb);
    EventCombatHard a(&p, 100000, 22, 22, 22, 22);
    EventFinal ef(&p, 22, 22, 22, 22, &a);
    f.get_cell(3, 3)->set_event(&cemb);
    f.get_cell(4, 3)->set_event(&emb);
    f.get_cell(6,6)->set_event(&ef);
    f.set_event_for_null(&ceb);
    fa.player_menu();
    return 0;
}