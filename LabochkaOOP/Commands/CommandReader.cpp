//
// Created by corvussharp on 21.09.22.
//

#include "CommandReader.h"

    void CommandReader::set_size(){
        while (true){

            std::cout<<"Введите Высоту:"; std::cin>>height;

            std::cout<<"Введите ширину:"; std::cin>>width;
            if(valid_arg(height) && valid_arg(width)){
                break;
            } else{
               auto a = arg_error();
            }
        }
    }
    char CommandReader::field_choice(){
        std::cout << "Хотите ли вы изменить размеры поля?\n Если нет Введите 'X' : ";
        std::cin>>sym;
        return sym;
    }
    int CommandReader::arg_error(){
        std::cout <<"\nВы вели отрицательно значение, попробуйте снова"<<std::endl;
        return 0;
    }
    bool CommandReader::valid_arg(int a){
        if (a<=0){
            return false;
        }
        return true;
    }
    void CommandReader::check_step(){

        std::cout<<"Команды :\n\t\tw - движение вперед\n\t\ts - движение вниз\n\t\t"
                   "d - движение вправо\n\t\ta - движение влево\n\t\te - выйти из игры"<<std::endl;
        std::cout<<" Введите команду: ";
        std::cin>>sym;
        switch (sym) {
            case 'w':
                step = Person::UP;
                break;
            case 's':
                step = Person::DOWN;
                break;
            case 'd':
                step = Person::RIGHT;
                break;
            case 'a':
                step = Person::LEFT;
                break;
            case 'e':
                step = Person::EXIT;
                std::cerr<<"Игра Закончена!"<<std::endl;
                break;
            default:
                std::cerr<<"Вы ввели не правильную команду"<<std::endl;
                step = Person::NOTHING;
                break;
        }
    }

    int CommandReader::get_height() const{
        return height;
    }

    int CommandReader::get_width()const{
        return width;
    }
    char CommandReader::get_sym()const{
        return sym;
    }
    Person::STEP CommandReader::get_step() const{
        return step;
    }

