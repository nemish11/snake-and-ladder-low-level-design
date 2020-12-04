#include <iostream>
#include "models/import.h"
#include "services/import.h"
#include "uuid/uuid.h"
#include "services/SnakeAndLadderService.h"

using namespace std;

int main() {
    srand(time(0));

    int noOfSnakes;
    cout<<"enter number of snakes"<<endl;
    cin >> noOfSnakes;

    vector<Snake> snakes;
    for (int i = 0; i < noOfSnakes; i++) {
        int start, end;
        cin>>start>>end;

        Snake snake(start, end);
        snakes.push_back(snake);
    }

    cout<<"enter number of ladders"<<endl;
    int noOfLadders; cin >> noOfLadders;

    vector<Ladder> ladders;
    for (int i = 0; i < noOfLadders; i++) {
        int start, end;
        cin>>start>>end;

        Ladder ladder(start, end);
        ladders.push_back(ladder);
    }

    int noOfPlayers;
    cout<<"enter number of players"<<endl;
    cin >> noOfPlayers;

    vector<Player> players;
    for (int i = 0; i < noOfPlayers; i++) {

        string name;
        cin>>name;

        uuid_t uuid_r;
        uuid_generate(uuid_r);
        char *st = new char [50];
        uuid_unparse(uuid_r, st);
        string id1(st);

        Player player(name, id1);
        players.push_back(player);
    }

    SnakeAndLadderService *snakeAndLadderService = new SnakeAndLadderService();
    snakeAndLadderService->setPlayers(players);
    snakeAndLadderService->setSnakes(snakes);
    snakeAndLadderService->setLadders(ladders);

    snakeAndLadderService->startGame();

    return 0;
}
