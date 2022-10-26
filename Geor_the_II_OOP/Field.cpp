#include "Field.h"
Field::Field(unsigned int w, unsigned int l, std::pair <long int, long int> c) : width(w), length(l), coord(c), event_for_null(nullptr){
    if(width == 0 || length == 0){
        throw("Error! Field class object cannot have a width and/or length value of 0.\n");
    }
    coord.first %= (long int) w;
    coord.second %= (long int) l;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field(unsigned int w, unsigned int l, long int x, long int y) : width(w), length(l), event_for_null(nullptr){
    if(width == 0 || length == 0){
        throw("Error! Field class object cannot have a width and/or length value of 0.\n");
    }
    coord.first = x % (long int) w;
    coord.second = y % (long int) l;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field(unsigned int w, unsigned int l) : width(w), length(l), event_for_null(nullptr){
    if(width == 0 || length == 0){
        throw("Error! Field class object cannot have a width and/or length value of 0.\n");
    }
    coord.first = 0;
    coord.second = 0;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field(unsigned int w, unsigned int l, std::pair <long int, long int> c, CellEvent *e) : width(w), length(l), coord(c), event_for_null(e){
    if(width == 0 || length == 0){
        throw("Error! Field class object cannot have a width and/or length value of 0.\n");
    }
    coord.first %= (long int) w;
    coord.second %= (long int) l;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field(unsigned int w, unsigned int l, long int x, long int y, CellEvent *e) : width(w), length(l), event_for_null(e){
    if(width == 0 || length == 0){
        throw("Error! Field class object cannot have a width and/or length value of 0.\n");
    }
    coord.first = x % (long int) w;
    coord.second = y % (long int) l;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field(unsigned int w, unsigned int l, CellEvent *e) : width(w), length(l), event_for_null(e){
    if(width == 0 || length == 0){
        throw("Error! Field class object cannot have a width and/or length value of 0.\n");
    }
    coord.first = 0;
    coord.second = 0;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field() : width(10), length(10), event_for_null(nullptr){
    coord.first = 0;
    coord.second = 0;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(Cell());
        }
    }
}
Field::Field(const Field& f){
    event_for_null = f.event_for_null;
    coord = f.coord;
    width = f.width;
    length = f.length;
    for(int i = 0; i < width; i++){
        map.push_back(std::vector<Cell>());
        for(int j = 0; j < length; j++){
            map[i].push_back(f.map[i][j]);
        }
    }
}
Field::Field(Field&& f){
    std::swap(event_for_null, f.event_for_null);
    std::swap(coord, f.coord);
    std::swap(width, f.width);
    std::swap(length, f.length);
    std::swap(map, f.map);
}
Field& Field::operator=(const Field& f){
    if(this != &f){
        event_for_null = f.event_for_null;
        coord = f.coord;
        width = f.width;
        length = f.length;
        for(int i = 0; i < width; i++){
            map[i].clear();
        }
        map.clear();
        for(int i = 0; i < width; i++){
            map.push_back(std::vector<Cell>());
            for(int j = 0; j < length; j++){
                map[i].push_back(f.map[i][j]);
            }
        }
    }
    return *this;
}
Field& Field::operator=(Field&& f){
    if(this != &f){
        std::swap(event_for_null, f.event_for_null);
        std::swap(coord, f.coord);
        std::swap(width, f.width);
        std::swap(length, f.length);
        std::swap(map, f.map);
    }
    return *this;
}
bool Field::operator==(const Field& f){
    if((width != f.width) || (length != f.length)){
        return false;
    }
    for(int x = 0; x < width; x++){
        for(int y = 0; y < length; y++){
            if(map[x][y] != f.map[x][y]){
                return false;
            }
        }
    }
    return true;
}
bool Field::operator!=(const Field& f){
    return !(this->operator==(f));
}
bool Field::move_player(Direction d){
    std::pair <long int, long int> new_coord = coord;
    switch (d){
        case up:
            new_coord.second+=1;
            break;
        case up_right:
            new_coord.second+=1;
            new_coord.first+=1;
            break;
        case right:
            new_coord.first+=1;
            break;
        case down_right:
            new_coord.second-=1;
            new_coord.first+=1;
            break;
        case down:
            new_coord.second-=1;
            break;
        case down_left:
            new_coord.second-=1;
            new_coord.first-=1;
            break;
        case left:
            new_coord.first-=1;
            break;
        case up_left:
            new_coord.second+=1;
            new_coord.first-=1;
            break;
        default:
            return false;
    }
    if(this->get_cell(new_coord)->is_passable()){
        this->set_coord(new_coord);
        return true;
    }
    return false;
}
GameStatus Field::trigger_cell(){
    Cell *cell = this->get_player_cell();
    CellEvent *event = cell->get_event();
    GameStatus status = status_quo;
    if(event){
        status = event->trigger();
        if(status == null_event){
            cell->set_event(nullptr);
            return status_quo;
        }
    }
    else{
        status = event_for_null->trigger();
        if(status == null_event){
            status = status_quo;
        }
    }
    return status;
}
void Field::set_coord(std::pair <long int, long int> c){
    coord.first = ((c.first % width) + width) % width;
    coord.second = ((c.second % length) + length) % length;
}
void Field::set_coord(long int x, long int y){
    coord.first = ((x % width) + width) % width;
    coord.second = ((y % length) + length) % length;
}
std::pair <long int, long int>  Field::get_coord(){
    return coord;
}
Cell *Field::get_player_cell(){
    return get_cell(coord);
}
Cell *Field::get_cell(std::pair <long int, long int> p){
    long int lwidth = long(width);
    long int llength = long(length);
    p.first = ((p.first % lwidth) + lwidth) % lwidth;
    p.second = ((p.second % llength) + llength) % llength;
    return &map[p.first][p.second];
}
Cell *Field::get_cell(long int x, long int y){
    long int lwidth = long(width);
    long int llength = long(length);
    x = ((x % lwidth) + lwidth) % lwidth;
    y = ((y % llength) + llength) % llength;
    return &map[x][y];
}
unsigned int Field::get_width(){
    return width;
}
unsigned int Field::get_length(){
    return length;
}
void Field::set_event_for_null(CellEvent *e){
    event_for_null = e;
}
CellEvent *Field::get_event_for_null(){
    return event_for_null;
}