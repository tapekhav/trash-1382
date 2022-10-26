#ifndef MAIN_CPP_OBSERVER_H
#define MAIN_CPP_OBSERVER_H


class Observer {
public:
//    virtual void Update(Message const &msg) = 0;
    virtual void update() = 0;
    virtual ~Observer() {};
};


#endif //MAIN_CPP_OBSERVER_H
