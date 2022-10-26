#include "SetterCellEvent.h"
void SetterCellEvent::reset_null(){
    std::mt19937 r;
    std::random_device device;
    r.seed(device());
    std::list <Cell *> null_list;
    for(long int x = 0; x < field->get_width(); x++){
        for(long int y = 0; y < field->get_length(); y++){
            Cell *cell = field->get_cell(x, y);
            if(!cell->get_event()){
                null_list.push_back(cell);
            }
        }
    }
    const unsigned int null_amount = null_list.size();
    for(unsigned int i = 0; i < percent_events.size(); i++){
        unsigned int amount = null_amount * ((double) percent_events[i].second / (double) total_percent);
        for(unsigned int j = amount; j > 0; j--){
            long int k = r() % null_list.size();
            auto iter = null_list.begin();
            std::advance(iter, k);
            (*iter)->set_event(percent_events[i].first);
            null_list.erase(iter);
        }
    }
}
void SetterCellEvent::reset_all(){
    std::mt19937 r;
    std::random_device device;
    r.seed(device());
    std::list <Cell *> null_list;
    if(total_singular > field->get_width() * field->get_length()){
        throw("Error! SetterCellEvent class object have singular events more than Field class object have cell.\n");
    }
    for(long int x = 0; x < field->get_width(); x++){
        for(long int y = 0; y < field->get_length(); y++){
            Cell *cell = field->get_cell(x, y);
            cell->set_event(nullptr);
            null_list.push_back(cell);
        }
    }
    for(unsigned int i = 0; i < singular_events.size(); i++){
        for(unsigned int j = singular_events[i].second; j > 0; j--){
            long int k = r() % null_list.size();
            auto iter = null_list.begin();
            std::advance(iter, k);
            (*iter)->set_event(percent_events[i].first);
            null_list.erase(iter);
        }
    }
    const unsigned int null_amount = null_list.size();
    for(unsigned int i = 0; i < percent_events.size(); i++){
        unsigned int amount = null_amount * ((double) percent_events[i].second / (double) total_percent);
        for(unsigned int j = amount; j > 0; j--){
            long int k = r() % null_list.size();
            auto iter = null_list.begin();
            std::advance(iter, k);
            (*iter)->set_event(percent_events[i].first);
            null_list.erase(iter);
        }
    }
}
SetterCellEvent::SetterCellEvent(Field *f){
    field = f;
}
SetterCellEvent::SetterCellEvent(const SetterCellEvent& s){
    field - s.field;
    total_percent = s.total_percent;
    total_singular = s.total_singular;
    for(unsigned int i = 0; i < percent_events.size(); i++){
        percent_events.push_back(s.percent_events[i]);
    }
    for(unsigned int i = 0; i < singular_events.size(); i++){
        singular_events.push_back(s.singular_events[i]);
    }
}
SetterCellEvent::SetterCellEvent(SetterCellEvent&& s){
    std::swap(field, s.field);
    std::swap(total_percent, s.total_percent);
    std::swap(total_singular, s.total_singular);
    std::swap(percent_events, s.percent_events);
    std::swap(singular_events, s.singular_events);
}
SetterCellEvent& SetterCellEvent::operator=(const SetterCellEvent& s){
    if(this != &s){
        field - s.field;
        total_percent = s.total_percent;
        total_singular = s.total_singular;
        for(unsigned int i = 0; i < percent_events.size(); i++){
            percent_events.push_back(s.percent_events[i]);
        }
        for(unsigned int i = 0; i < singular_events.size(); i++){
            singular_events.push_back(s.singular_events[i]);
        }
    }
    return *this;
}
SetterCellEvent& SetterCellEvent::operator=(SetterCellEvent&& s){
    if(this != &s){
        std::swap(field, s.field);
        std::swap(total_percent, s.total_percent);
        std::swap(total_singular, s.total_singular);
        std::swap(percent_events, s.percent_events);
        std::swap(singular_events, s.singular_events);
    }
    return *this;
}
void SetterCellEvent::set_percent_event(CellEvent *e, unsigned int p){
    std::pair <CellEvent *, unsigned int> pe;
    pe.first = e;
    pe.second = p;
    set_percent_event(pe);
}
void SetterCellEvent::set_percent_event(std::pair <CellEvent *, unsigned int> pe){
    if(pe.second == 0){
        pe.second = 1;
    }
    percent_events.push_back(pe);
}
void SetterCellEvent::set_singular_event(CellEvent *e, unsigned int s){
    std::pair <CellEvent *, unsigned int> se;
    se.first = e;
    se.second = s;
    set_singular_event(se);
}
void SetterCellEvent::set_singular_event(std::pair <CellEvent *, unsigned int> se){
    if(se.second == 0){
        se.second = 1;
    }
    singular_events.push_back(se);
}
void SetterCellEvent::set_field(Field *f){
    field = f;
}
std::pair <CellEvent *, unsigned int> SetterCellEvent::get_percent_event(unsigned int i){
    if(percent_events.size() != 0){
        return percent_events[i % percent_events.size()];
    }
    throw("Error! SetterCellEvent class object does not have a percent events.\n");
}
std::pair <CellEvent *, unsigned int> SetterCellEvent::get_singular_event(unsigned int i){
    if(singular_events.size() != 0){
        return singular_events[i % singular_events.size()];
    }
    throw("Error! SetterCellEvent class object does not have a singular events.\n");
}
unsigned int SetterCellEvent::get_percent_events_amount(){
    return percent_events.size();
}
unsigned int SetterCellEvent::get_singular_events_amount(){
    return singular_events.size();
}
Field *SetterCellEvent::get_field(){
    return field;
}
void SetterCellEvent::set(bool is_only_null){
    if(is_only_null){
        reset_null();
    }
    else{
        reset_all();
    }
}