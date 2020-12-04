//
// Created by Nemish on 04/12/20.
//

#include "SnakeAndLadderService.h"
#include "iostream"
#include "DiceService.h"
using namespace std;

SnakeAndLadderService::SnakeAndLadderService() {
    this->snakeAndLadderBoard = new SnakeAndLadderBoard(DEFAULT_BOARD_SIZE);
}

SnakeAndLadderService::SnakeAndLadderService(int boardSize) {
    this->snakeAndLadderBoard = new SnakeAndLadderBoard(boardSize);
}

void SnakeAndLadderService::setPlayers(vector<Player> &players) {
    this->initialNumberOfPlayers = players.size();
    map<string, int> playerPieces;

    for(Player player: players){
        Player *player_ref = new Player(player.getName(), player.getId());
        this->players.push(player_ref);
        this->snakeAndLadderBoard->setPlayerPiece(player.getId(), 0);
    }
}

void SnakeAndLadderService::setSnakes(vector<Snake> &snakes) {
    this->snakeAndLadderBoard->setSnakes(snakes);
}

void SnakeAndLadderService::setLadders(vector<Ladder> &ladders) {
    this->snakeAndLadderBoard->setLadders(ladders);
}

int SnakeAndLadderService::getNewPositionAfterGoingThroughSnakesAndLadders(int newPosition) {
    int previousPosition;

    do {
        previousPosition = newPosition;
        for (Snake snake : this->snakeAndLadderBoard->getSnakes()) {
            if (snake.getStart() == newPosition) {
                newPosition = snake.getEnd();
            }
        }

        for (Ladder ladder : this->snakeAndLadderBoard->getLadders()) {
            if (ladder.getStart() == newPosition) {
                newPosition = ladder.getEnd();
            }
        }
    } while (newPosition != previousPosition);

    return newPosition;
}

void SnakeAndLadderService::movePlayer(Player *player, int positions) {
    int oldPosition = this->snakeAndLadderBoard->getPlayerPieces()[player->getId()];
    int newPosition = oldPosition + positions;

    int boardSize = this->snakeAndLadderBoard->getSize();

    if (newPosition > boardSize) {
        newPosition = oldPosition;
    } else {
        newPosition = getNewPositionAfterGoingThroughSnakesAndLadders(newPosition);
    }

    this->snakeAndLadderBoard->setPlayerPiece(player->getId(), newPosition);

    cout << player->getName() << " rolled a " << positions << " and moved from " << oldPosition << " to " << newPosition << endl;
}

int SnakeAndLadderService::getTotalValueAfterDiceRolls() {
    return DiceService::roll();
}

bool SnakeAndLadderService::hasPlayerWon(Player *player) {
    int playerPosition = this->snakeAndLadderBoard->getPlayerPieces()[player->getId()];
    int winningPosition = this->snakeAndLadderBoard->getSize();
    return playerPosition == winningPosition;
}

bool SnakeAndLadderService::isGameCompleted() {
    int currentNumberOfPlayers = players.size();
    return currentNumberOfPlayers < initialNumberOfPlayers;
}

void SnakeAndLadderService::startGame() {
    while (!isGameCompleted()) {
        int totalDiceValue = getTotalValueAfterDiceRolls();

        Player *currentPlayer = this->players.front();
        this->players.pop();

        movePlayer(currentPlayer, totalDiceValue);

        if (hasPlayerWon(currentPlayer)) {
            cout<< currentPlayer->getName() << " wins the game" << endl;
            this->snakeAndLadderBoard->erasePlayer(currentPlayer->getId());
        } else {
            players.push(currentPlayer);
        }
    }
}
