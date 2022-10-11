#pragma once


class CellType {
public:
    CellType() = default;

    virtual ~CellType() = default;

    virtual void execute() = 0;

    virtual bool get_pass() = 0;
};

class CoinType : public CellType {
public:
    CoinType() = default;

    ~CoinType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class EnemyType : public CellType {
public:
    EnemyType() = default;

    ~EnemyType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class WallVertType : public CellType {
public:
    WallVertType() = default;

    ~WallVertType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class WallHorType : public CellType {
public:
    WallHorType() = default;

    ~WallHorType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class HealType : public CellType {
public:

    HealType() = default;

    ~HealType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class EmptyType : public CellType {
public:
    EmptyType() = default;

    ~EmptyType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class PlayerType : public CellType {
public:
    PlayerType() = default;

    ~PlayerType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = true;
};


class FixType : public CellType {
public:
    FixType() = default;

    ~FixType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass = false;
};


