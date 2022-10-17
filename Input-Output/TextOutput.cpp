#include "TextOutput.h"

void TextOutput::StartText(){
    std::cout<<"Добро пожаловать! Для взаимодействия с игрой используйте консоль!\n";
    std::cout<<"Управление:\n";
    std::cout<<"\tПередвижение: wasd\n";
    std::cout<<"\tQ - выход\n";
    std::cout<<'\n';
    std::cout<<"Хотите ли Вы задать параметры поля?\n";
    std::cout<<"\tY *height* *width* - задать поле с опеределённой высотой и шириной\n";
    std::cout<<"\tN - задать поле со стандартными размерами\n\n";
    std::cout<<"Максимальные размеры поля: ширина - 50, высота - 35\n";
    std::cout<<"При некорректных данных значения будут приведены к стандартным\n";

}