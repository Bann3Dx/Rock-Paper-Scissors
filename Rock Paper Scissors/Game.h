#pragma once
#include "Player.h"

class Game{
private:
    Player* player1;
    Player* player2;
    int score1,score2,rounds,cround;
public:
    Game(Player* p1,Player*p2,int Totalrounds);
    void play();
};