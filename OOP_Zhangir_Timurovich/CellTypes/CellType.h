#pragma once


class CellType {
public:
    virtual void execute() = 0;
};

class CoinType : public CellType {
public:
    void execute() override {};
};


class EnemyType : public CellType {
public:
    void execute() override {};
};


class WallVertType : public CellType {
public:
    void execute() override {};
};


class WallHorType : public CellType {
public:
    void execute() override {};
};


class HealType : public CellType {
public:
    void execute() override {};
};


class EmptyType : public CellType {
public:
    void execute() override {};
};


class PlayerType : public CellType {
public:
    void execute() override {};
};


class FixType : public CellType {
public:
    void execute() override {};
};


