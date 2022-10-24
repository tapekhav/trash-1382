#ifndef LABS_EVENTMSG_H
#define LABS_EVENTMSG_H

#include "Message.h"

class EventMsg : public Message {
public:
    explicit EventMsg(std::string);
    std::string get_msg() override;
private:
    friend std::ostream& operator<<(std::ostream&, EventMsg*);
    std::string msg;
};


#endif
