#pragma once

class CellType {
public:
    CellType() = default;

    virtual ~CellType() = default;

    virtual void execute() = 0;

    virtual bool get_pass() = 0;

};





























