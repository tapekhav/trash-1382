#pragma once


class CellType {
    virtual void execute() = 0;
};

class CoinType : public CellType {
    void execute() override;
};


class EnemyType : public CellType {
    void execute() override;
};


class WallVertType : public CellType {
    void execute() override;
};


class WallHorType : public CellType {
    void execute() override;
};


class HealType : public CellType {
    void execute() override;
};


class EmptyType : public CellType {
    void execute() override;
};


class PlayerType : public CellType {
    void execute() override;
};


class FixType : public CellType {
    void execute() override;
};


