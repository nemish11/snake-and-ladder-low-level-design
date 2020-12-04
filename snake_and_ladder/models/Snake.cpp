//
// Created by Nemish on 04/12/20.
//

#include "Snake.h"

Snake::Snake() {}

Snake::Snake(int start, int end){
    this->start = start;
    this->end = end;
}

int Snake::getEnd() {
    return this->end;
}

int Snake::getStart() {
    return this->start;
}
