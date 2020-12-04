//
// Created by Nemish on 04/12/20.
//

#ifndef SNAKE_AND_LADDER_DICESERVICE_H
#define SNAKE_AND_LADDER_DICESERVICE_H
#include "random"

class DiceService {
public:
    static int roll(){
        return rand()%6 + 1;
    }
};


#endif //SNAKE_AND_LADDER_DICESERVICE_H
