#include "Message.h"

Message::Message(const std::string& prefix, const std::string& info, int num) {
    this->prefix = prefix;
    this->info = info;
}

std::string Message::get_msg() {
    return info;
}

std::string Message::get_prefix() const {
    return prefix;
}

std::ostream &operator<<(std::ostream& out, Message msg) {
    out << msg.get_prefix();
    out << msg.get_msg();
    return out;
}

void Message::update() {
    prefix += ": ";
    info += "\n";
}
