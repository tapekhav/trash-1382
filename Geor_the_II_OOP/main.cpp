#include <iostream>
#include "FacadePlayer.h"
#include "FieldView.h"
#include "Observer.h"
#include "Log.h"
#include "EventCasing.h"
#include "EventMakeBorder.h"
#include "EventBonus.h"
int main(){
    Field f(10, 10);
    f.get_cell(1, 1)->set_passable(false);
    Player p(100, 20, 20, 20, 20, 200);
    Log jj("Text.txt");
    Observer o(&jj);
    FacadePlayer fa(&p, &f, &o);
    EventBonus eb(&p);
    EventCasing ceb(&eb, 0.08);
    EventMakeBorder emb(&f);
    EventCasing cemb(&emb);
    f.get_cell(3, 3)->set_event(&cemb);
    f.get_cell(4, 3)->set_event(&emb);
    f.set_event_for_null(&ceb);
    fa.game_start();
    return 0;
}