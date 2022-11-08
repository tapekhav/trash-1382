#ifndef LABS_ICONTROLLER_H
#define LABS_ICONTROLLER_H



class IController {
public:
    virtual char get_step() = 0;
    virtual ~IController() = default;
};

#endif
