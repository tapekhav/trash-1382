//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_OBSERVER_H
#define LABOCHKAOOP_OBSERVER_H
#include "vector"

class Observer {
public:

    virtual void update() = 0;
    virtual ~Observer() = default;
};


#endif //LABOCHKAOOP_OBSERVER_H
