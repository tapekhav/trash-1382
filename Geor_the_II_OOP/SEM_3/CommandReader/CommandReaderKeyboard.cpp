#include "CommandReaderKeyboard.h"
CommandReaderKeyboard::CommandReaderKeyboard(){
    setting.push_back({up, 'w'});
    setting.push_back({up_right, 'e'});
    setting.push_back({right, 'd'});
    setting.push_back({down_right, 'x'});
    setting.push_back({down, 's'});
    setting.push_back({down_left, 'z'});
    setting.push_back({left, 'a'});
    setting.push_back({up_left, 'q'});
    setting.push_back({play, 'p'});
    setting.push_back({quit, 'q'});
    setting.push_back({stay, 'f'});
}
CommandReaderKeyboard::CommandReaderKeyboard(std::string file_name) : CommandReaderKeyboard(){
    std::ifstream file(file_name, std::ios_base::in);
    if(!file.is_open()){
        return;
    }
    std::string command;
    while(getline(file, command)){
        //std::cout<<command<<std::endl;
        if(command.find("up=") != -1){
            setting[0] = {up, command[command.length() - 1]};
        }
        else if(command.find("up_right=") != -1){
            setting[1] = {up_right, command[command.length() - 1]};
        }
        else if(command.find("down_right=") != -1){
            setting[3] = {down_right, command[command.length() - 1]};
        }
        else if(command.find("right=") != -1){
            setting[2] = {right, command[command.length() - 1]};
        }
        else if(command.find("down=") != -1){
            setting[4] = {down, command[command.length() - 1]};
        }
        else if(command.find("down_left=") != -1){
            setting[5] = {down_left, command[command.length() - 1]};
        }
        else if(command.find("up_left=") != -1){
            setting[7] = {up_left, command[command.length() - 1]};
        }
        else if(command.find("left=") != -1){
            setting[6] = {left, command[command.length() - 1]};
        }
        else if(command.find("play=") != -1){
            setting[8] = {play, command[command.length() - 1]};
        }
        else if(command.find("quit=") != -1){
            setting[9] = {quit, command[command.length() - 1]};
        }
        else if(command.find("stay=") != -1){
            setting[10] = {stay, command[command.length() - 1]};
        }
    }
    file.close();
}
CommandOperand CommandReaderKeyboard::get_command(){
    char d;
    std::cin >> d;
    for(int i = 0; i < 11; i++){
        if(d == setting[i].second){
            return setting[i].first;
        }
    }
    return stay;
}
std::string CommandReaderKeyboard::get_symbol(CommandOperand co){
   for(int i = 0; i < 11; i++){
        if(co == setting[i].first){
            std::string s = "";
            s.push_back(setting[i].second);
            return s;
        }
    } 
}
