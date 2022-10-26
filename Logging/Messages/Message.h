#ifndef LABS_MESSAGE_H
#define LABS_MESSAGE_H

#include <string>

class Message {
public:
    explicit Message(const std::string&, const std::string&, int num = -1);
    std::string get_msg();
    std::string get_prefix() const;
    friend std::ostream& operator<<(std::ostream&, Message);

    void update();

private:
    std::string prefix;
    std::string   info;
    int num;
};


#endif
