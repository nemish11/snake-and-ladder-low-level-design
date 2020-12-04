//
// Created by Nemish on 04/12/20.
//

#ifndef SNAKE_AND_LADDER_PLAYER_H
#define SNAKE_AND_LADDER_PLAYER_H
#include "string"
#include "cstring"
using namespace std;

class Player {
private:
    string name, id;

public:
    Player();
    Player(string name, string id);
    string getName();
    string getId();
};


#endif //SNAKE_AND_LADDER_PLAYER_H
