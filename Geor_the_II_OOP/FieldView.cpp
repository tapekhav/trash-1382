#include "FieldView.h"
void FieldView::set_field(Field *field){
    CellView a;
    if(field == nullptr){
        throw("Error! FieldView class object cannot work with nullptr.\n");
    }
    if(!map.empty()){
        for(unsigned int i = 0; i < map.size(); i++){
            map[i].clear();
        }
        map.clear();
    }
    width = field->get_width();
    length = field->get_length();
    for(long int i = 0; i < width; i++){
        map.push_back(std::vector<char>());
        for(long int j = 0; j < length; j++){
            map[i].push_back(a.cell_view(field->get_cell(i, j)));
        }
    }
    map[((field->get_coord().first % (long) width) + (long) width) % (long) width][((field->get_coord().second % (long) length) + (long) length) % (long) length] = 'Y';
}
std::vector< std::vector< char >> &FieldView::get_field(){
    return map;
}
void FieldView::print(){
    for(unsigned int j = length; j > 0; j--){
        for(unsigned int i = 0; i < width; i++){
            std::cout<<map[i][j-1]<<' ';
        }
        std::cout<<'\n';
    }
}