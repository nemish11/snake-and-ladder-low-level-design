//
// Created by Nemish on 04/12/20.
//

#include "Player.h"
using namespace std;

Player::Player() {}

Player::Player(string name, string id){
    string s1(name);
    string s2(id);
    this->name = s1;
    this->id = s2;
}

string Player::getName(){
    return this->name;
}

string Player::getId() {
    return this->id;
}
