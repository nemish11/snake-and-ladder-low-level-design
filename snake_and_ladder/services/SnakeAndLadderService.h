//
// Created by Nemish on 04/12/20.
//

#ifndef SNAKE_AND_LADDER_SNAKEANDLADDERSERVICE_H
#define SNAKE_AND_LADDER_SNAKEANDLADDERSERVICE_H
#include "../models/import.h"
#include "queue"

class SnakeAndLadderService {
private:
    SnakeAndLadderBoard *snakeAndLadderBoard;
    int initialNumberOfPlayers;
    queue<Player*> players;

    static const int DEFAULT_BOARD_SIZE = 100;

    int getNewPositionAfterGoingThroughSnakesAndLadders(int newPosition);
    void movePlayer(Player *player, int positions);
    int getTotalValueAfterDiceRolls();
    bool hasPlayerWon(Player *player);
    bool isGameCompleted();

public:
    SnakeAndLadderService();
    SnakeAndLadderService(int boardSize);
    void setPlayers(vector<Player> &players);
    void setSnakes(vector<Snake> &snakes);
    void setLadders(vector<Ladder> &ladders);
    void startGame();
};


#endif //SNAKE_AND_LADDER_SNAKEANDLADDERSERVICE_H
