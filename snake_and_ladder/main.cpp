#include <iostream>
#include "models/Snake.h"
#include "models/Ladder.h"
#include "models/Player.h"
#include "uuid/uuid.h"
#include "services/DiceService.h"

using namespace std;

int main() {
    srand(time(0));

    std::cout << "Hello, World!" << std::endl;
    Ladder l(2,3);
    cout<<l.getStart()<<" "<<l.getEnd()<<endl;

    Snake s(4,5);
    cout << s.getStart() <<" "<<s.getEnd()<<endl;

    uuid_t uuid_r;
    uuid_generate(uuid_r);
    char *st = new char [33];
    uuid_unparse(uuid_r, st);
    cout << st <<endl;
    std::string id(st);
    Player p("Nemish", id);
    cout<< p.getId() << " " << p.getName()<<endl;

    cout<<DiceService::roll()<<endl;

    return 0;
}
