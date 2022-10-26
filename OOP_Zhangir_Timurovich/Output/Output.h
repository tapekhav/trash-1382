//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_OUTPUT_H
#define MAIN_CPP_OUTPUT_H

#include <string>


class Output {
public:
    virtual ~Output() = default;

    virtual Output &operator<<(std::string message) = 0;
};


#endif //MAIN_CPP_OUTPUT_H
