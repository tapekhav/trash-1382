#ifndef LABS_GAMEMSG_H
#define LABS_GAMEMSG_H

#include "Message.h"

class GameMsg : public Message {
public:
    explicit GameMsg(std::string);
    std::string get_msg() override;
private:
    friend std::ostream& operator<<(std::ostream&, GameMsg*);
    std::string msg;
};


#endif
