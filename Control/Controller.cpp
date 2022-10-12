#include "Controller.h"


Controller::Controller() : field(Field()), field_view(FieldView(&field)),
                           player(Player()), player_view(PlayerView(&player)) {}

void Controller::set_field(int width, int height) {
    field = Field(width, height);
    field.make_field();
}

void Controller::set_field_standard() {
    field = Field();
    field.make_field();
}

void Controller::set_step(Player::STEP step) {
    check_event(field.change_player_pos(step));
}

bool Controller::end_game() const {
    return player.get_health() <= 0;
}

bool Controller::win_game() const {
    return player.get_keys() == 2;
}

void Controller::check_event(Event *event) {
    if (event != nullptr) {
        if (auto tmp = dynamic_cast<EventPlayer*>(event))
            tmp->execute(player);
        if (auto temp = dynamic_cast<EventField*>(event))
            temp->execute(field);
    }
}
