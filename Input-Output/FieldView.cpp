#include "FieldView.h"

void FieldView::DrawField(Field& vField){
    std::cout<<"\033c";
    for(int i = 0; i < vField.ShowWidth()+2; ++i){
        std::cout<<"█";
    }
    std::cout<<std::endl;
    
    for(int i = 0; i < vField.ShowHeight(); ++i){
        for(int j = 0; j < vField.ShowWidth()+2;++j){
            if(j == 0 || j == vField.ShowWidth()+1)
                std::cout<<"█";
            else
                std::cout<<vField.ShowCurField()[i][j-1].ShowCurIcon();
        }
        std::cout<<std::endl;
    }

    for(int i = 0; i < vField.ShowWidth()+2; ++i){
        std::cout<<"█";
    }
    std::cout<<std::endl;
}


