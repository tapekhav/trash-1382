#ifndef LABS_INPUTMSG_H
#define LABS_INPUTMSG_H

#include "Message.h"

class InputMsg : public Message {
public:
    explicit InputMsg(std::string);
    std::string get_msg() override;
private:
    friend std::ostream& operator<<(std::ostream&, InputMsg*);
    std::string msg;
};


#endif
