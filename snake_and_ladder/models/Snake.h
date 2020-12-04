//
// Created by Nemish on 04/12/20.
//

#ifndef SNAKE_AND_LADDER_SNAKE_H
#define SNAKE_AND_LADDER_SNAKE_H


class Snake {
private:
    int start, end;
public:
    Snake();
    Snake(int start, int end);
    int getStart();
    int getEnd();
};


#endif //SNAKE_AND_LADDER_SNAKE_H
