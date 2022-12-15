#ifndef TRASH_1382_MEMENTO_H
#define TRASH_1382_MEMENTO_H

#include <string>

class Memento {
public:
    explicit Memento(const std::string&);
    std::string get_data() const;
private:
    std::string data;
};


#endif
