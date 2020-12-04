//
// Created by Nemish on 04/12/20.
//

#include "Ladder.h"

Ladder::Ladder() {}

Ladder::Ladder(int start, int end){
    this->start = start;
    this->end = end;
}

int Ladder::getEnd() {
    return this->end;
}

int Ladder::getStart() {
    return this->start;
}
