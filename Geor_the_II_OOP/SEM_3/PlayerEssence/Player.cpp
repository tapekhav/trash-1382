#include "Player.h"
Player::Player(int h, int s, int e, int d, int a, unsigned int c) : hit_point(h), strength(s), endurance(e), dexterity(d), armor(a), coins(c){}
Player::Player() : hit_point(0), strength(0), endurance(0), dexterity(0), armor(0), coins(0){}
Player::Player(const Player& p) : hit_point(p.hit_point), strength(p.strength), endurance(p.endurance), dexterity(p.dexterity), armor(p.armor), coins(p.coins){}
Player::Player(Player&& p){
    std::swap(hit_point, p.hit_point);
    std::swap(strength, p.strength);
    std::swap(endurance, p.endurance);
    std::swap(dexterity, p.dexterity);
    std::swap(armor, p.armor);
    std::swap(coins, p.coins);
}
Player& Player::operator=(const Player& p){
    if(this != &p){
        hit_point = p.hit_point;
        strength = p.strength;
        endurance = p.endurance;
        dexterity = p.dexterity;
        armor = p.armor;
        coins = p.coins;
    }
    return *this;
}
Player& Player::operator=(Player&& p){
    if(this != &p){
        std::swap(hit_point, p.hit_point);
        std::swap(strength, p.strength);
        std::swap(endurance, p.endurance);
        std::swap(dexterity, p.dexterity);
        std::swap(armor, p.armor);
        std::swap(coins, p.coins);
    }
    return *this;
}
bool Player::operator==(const Player& p){
    if(hit_point == p.hit_point && strength == p.strength && endurance == p.endurance && dexterity == p.dexterity && armor == p.armor && coins == p.coins){
        return true;
    }
    return false;
}
bool Player::operator!=(const Player& p){
    return !(this->operator==(p));
}
void Player::set_hit_point(int new_hit_point){
    hit_point = new_hit_point;
}
void Player::set_strength(int new_strength){
    strength = new_strength;
}
void Player::set_endurance(int new_endurance){
    endurance = new_endurance;
}
void Player::set_dexterity(int new_dexterity){
    dexterity = new_dexterity;
}
void Player::set_armor(int new_armor){
    armor = new_armor;
}
void Player::set_coins(unsigned int c){
    coins = c;
}
bool Player::add_hit_point(int add_hitpoint){
    if(!(hit_point > 0 ^ add_hitpoint > 0) && (INT_MAX - abs(add_hitpoint) < abs(hit_point))){
        if(hit_point > 0){
            hit_point = INT_MAX;
            return true;
        }
        else{
            hit_point = INT_MIN;
            return false;
        }
    }
    else{
        hit_point += add_hitpoint;
    }
    if(hit_point >= 0){
        return true;
    }
    else{
        return false;
    }
}
void Player::add_strength(int add_strength){
    if(!(strength > 0 ^ add_strength > 0) && (INT_MAX - abs(add_strength) < abs(strength))){
        if(strength > 0){
            strength = INT_MAX;
        }
        else{
            strength = INT_MIN;
        }
    }
    else{
        strength += add_strength;
    }
}
void Player::add_endurance(int add_endurance){
    if(!(endurance > 0 ^ add_endurance > 0) && (INT_MAX - abs(add_endurance) < abs(endurance))){
        if(endurance > 0){
            endurance = INT_MAX;
        }
        else{
            endurance = INT_MIN;
        }
    }
    else{
        endurance += add_endurance;
    }
}
void Player::add_dexterity(int add_dexterity){
    if(!(dexterity > 0 ^ add_dexterity > 0) && (INT_MAX - abs(add_dexterity) < abs(dexterity))){
        if(dexterity > 0){
            dexterity = INT_MAX;
        }
        else{
            dexterity = INT_MIN;
        }
    }
    else{
        dexterity += add_dexterity;
    }
}
void Player::add_armor(int add_armor){
    if(!(armor > 0 ^ add_armor > 0) && (INT_MAX - abs(add_armor) < abs(armor))){
        if(armor > 0){
            armor = INT_MAX;
        }
        else{
            armor = INT_MIN;
        }
    }
    else{
        armor += add_armor;
    }
}
bool Player::add_coins(long int add_coins){
    if(add_coins >= 0){
        if(UINT_MAX - coins < (unsigned long int) add_coins){
            coins = UINT_MAX;
        }
        else{
            coins += (unsigned int) add_coins;
        }
    }
    else{
        if((unsigned long int) abs(add_coins) > coins){
            return false;
        }
        else{
            coins -= (unsigned int) abs(add_coins);
        }
    }
    return true;
}
int Player::get_hit_point(){
    return hit_point;
}
int Player::get_strength(){
    return strength;
}
int Player::get_endurance(){
    return endurance;
}
int Player::get_dexterity(){
    return dexterity;
}
int Player::get_armor(){
    return armor;
}
unsigned int Player::get_coins(){
    return coins;
}