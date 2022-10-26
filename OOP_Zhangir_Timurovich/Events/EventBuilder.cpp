#include "EventBuilder.h"
#include "../Logging/logs/GameObserver.h"

EventBuilder::EventBuilder(Field *field, Player *player) {
    this->field = field;
    this->player = player;
}

void EventBuilder::update_events() {
    Event *ev;
    for (int y = 0; y < field->get_height(); y++) {
        for (int x = 0; x < field->get_width(); x++) {
            if ((x == 1 || (x == field->get_width() - 1)) &&
                ((y == 1 || (y == field->get_height() - 1)))) {
                field->get_cell(x, y).set_event(new Collapse(this->field, this->player));
            } else if (x == 1 && y == field->get_height() / 2) {
                field->get_cell(x, y).set_event(new Increase(this->field, this->player));
            } else if (x == (field->get_width() - 1) && y == (field->get_height() / 2)) {
                field->get_cell(x, y).set_event(new Decrease(this->field, this->player));
            } else if ((x - y) % 7 == 0 && x % 5 == 0) {
                field->get_cell(x, y).set_event(new Enemy(this->player));
            } else if ((x + y) % 3 == 0 && x % 2 == 0 and y % 6 == 0) {
                field->get_cell(x, y).set_event(nullptr);
                field->get_cell(x, y).set_pass(false);
            } else if ((x + y) % 4 == 0 && x % 6 == 0) {
                field->get_cell(x, y).set_event(new GetCoin(this->player));
            } else if ((x - y) % 4 == 0 && x % 2 == 0 && y % 4 == 0) {
                field->get_cell(x, y).set_event(new Heal(this->player));
            }
        }
    }
}

Event *EventBuilder::create_HealEvent() {
    Heal *ev = new Heal(player);
    return ev;
};

Event *EventBuilder::create_CoinEvent() {
    GetCoin *ev = new GetCoin(player);
    return ev;
};

Event *EventBuilder::create_EnemyEvent() {
    Enemy *ev = new Enemy(player);
    return ev;
};

Event *EventBuilder::create_IncreaseEvent() {
    Increase *ev = new Increase(field, player);
    return ev;
};

Event *EventBuilder::create_DecreaseEvent() {
    Decrease *ev = new Decrease(field, player);
    return ev;
};

Event *EventBuilder::create_CollapseEvent() {
    Collapse *ev = new Collapse(field, player);
    return ev;
};

Event *EventBuilder::create_WinEvent() {
    Win *ev = new Win(player);
    return ev;
};

Event *EventBuilder::create_LoseEvent() {
    Lose *ev = new Lose(player);
    return ev;
};

