//
// Created by Nemish on 04/12/20.
//

#include "SnakeAndLadderBoard.h"

SnakeAndLadderBoard::SnakeAndLadderBoard(){}

SnakeAndLadderBoard::SnakeAndLadderBoard(int size) {
    this->size = size;
}

vector<Ladder> SnakeAndLadderBoard::getLadders() {
    return this->ladders;
}

vector<Snake> SnakeAndLadderBoard::getSnakes() {
    return this->snakes;
}

map<string, int> SnakeAndLadderBoard::getPlayerPieces() {
    return this->playerPieces;
}

int SnakeAndLadderBoard::getSize() {
    return this->size;
}

void SnakeAndLadderBoard::setLadders(vector<Ladder> &ladders) {
    this->ladders = ladders;
}

void SnakeAndLadderBoard::setSnakes(vector<Snake> &snakes) {
    this->snakes = snakes;
}

void SnakeAndLadderBoard::setPlayerPieces(map<string, int> &playerPieces) {
    this->playerPieces = playerPieces;
}

void SnakeAndLadderBoard::setPlayerPiece(string id, int position) {
    this->playerPieces[id] = position;
}

void SnakeAndLadderBoard::erasePlayer(string id) {
    this->playerPieces.erase(id);
}