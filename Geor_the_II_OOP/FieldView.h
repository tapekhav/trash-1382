#pragma once
#include <iostream>
#include "Field.h"
#include "CellView.h"
class FieldView{
    private:
        unsigned int width;
        unsigned int length;
        std::vector< std::vector< char >> map;
    public:
        void set_field(Field *field); //сделано; проверенно
        std::vector< std::vector< char >> &get_field(); //сделано
        //временно. Должен быть ревлезован в кантролере
        void print(); //сделано; проверенно
};