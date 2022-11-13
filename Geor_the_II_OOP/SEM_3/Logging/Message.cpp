#include "Message.h"
Message::Message(std::string t, MessageLevel l) : text(t), level(l){}
void Message::set_text(std::string t){
    text = t;
}
void Message::set_level(MessageLevel l){
    level = l;
}
std::string Message::get_text(){
    return text;
}
MessageLevel Message::get_level(){
    return level;
}
std::ostream &operator<<(std::ostream &os,  Message &message){
    os << message.text;
    return os;
}