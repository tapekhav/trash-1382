#pragma once

class Event {
    Event() = default;

    virtual void execute() = 0;
    Event(const Event& other) = default;
    virtual ~Event() = default;
};

