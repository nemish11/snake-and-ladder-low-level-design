//
// Created by Nemish on 04/12/20.
//

#ifndef SNAKE_AND_LADDER_SNAKEANDLADDERBOARD_H
#define SNAKE_AND_LADDER_SNAKEANDLADDERBOARD_H
#include "vector"
#include "map"
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"

using namespace std;

class SnakeAndLadderBoard {
private:
    int size;
    vector<Snake> snakes;
    vector<Ladder> ladders;
    map<string, int> playerPieces;

public:
    SnakeAndLadderBoard();
    SnakeAndLadderBoard(int size);
    void setSnakes(vector<Snake> &snakes);
    void setLadders(vector<Ladder> &ladders);
    void setPlayerPieces(map<string, int> &playerPieces);
    void setPlayerPiece(string id, int position);
    void erasePlayer(string id);

    vector<Snake> getSnakes();
    vector<Ladder> getLadders();
    map<string, int> getPlayerPieces();
    int getSize();
};


#endif //SNAKE_AND_LADDER_SNAKEANDLADDERBOARD_H
