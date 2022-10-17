#ifndef CELLTYPE_H
#define CELLTYPE_H

class CellType{
public:
    CellType(){}
    virtual ~CellType() = default;
};

class CellTypeStone : public CellType{
public:
    CellTypeStone(){}
};

class  CellTypeLand : public  CellType{
public:
    CellTypeLand(){}
};




#endif
