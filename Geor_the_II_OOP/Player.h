#pragma once
#include <climits>
#include <cmath>
class Player{
    private:
        int hit_point;
        int strength;
        int endurance;
        int dexterity;
        int armor;
        unsigned int coins;
    public:
        Player(int h, int s, int e, int d, int a, unsigned int c); //сделано; проверенно
        Player(); //сделано; проверенно
        Player(const Player& p); //сделано; проверенно
        Player(Player&& p); //сделано; проверенно
        Player& operator=(const Player& p); //сделано; проверенно
        Player& operator=(Player&& p); //сделано; проверенно
        bool operator==(const Player& p);
        bool operator!=(const Player& p);
        void set_hit_point(int new_hit_point); //сделано; проверенно
        void set_strength(int new_strength); //сделано; проверенно
        void set_endurance(int new_endurance); //сделано; проверенно
        void set_dexterity(int new_dexterity); //сделано; проверенно
        void set_armor(int new_armor); //сделано; проверенно
        void set_coins(unsigned int new_coins); //сделано; проверенно
        bool add_hit_point(int add_hit_point); //сделано; проверенно
        void add_strength(int add_strength); //сделано; проверенно
        void add_endurance(int add_endurance); //сделано; проверенно
        void add_dexterity(int add_dexterity); //сделано; проверенно
        void add_armor(int add_armor); //сделано; проверенно
        bool add_coins(long int add_coins); //сделано; проверенно
        int get_hit_point(); //сделано; проверенно
        int get_strength(); //сделано; проверенно
        int get_endurance(); //сделано; проверенно
        int get_dexterity(); //сделано; проверенно
        int get_armor(); //сделано; проверенно
        unsigned int get_coins(); //сделано; проверенно
};