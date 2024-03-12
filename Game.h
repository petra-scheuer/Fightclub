//
// Created by Petra Scheuer on 11.03.24.
//

#ifndef FIGHTCLUB_SCHEUER_GAME_H
#define FIGHTCLUB_SCHEUER_GAME_H

#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"


class Game {
private:
    Player spieler;
    Enemy gegner;
    int gametype_;
public:

    void startGame();
    void Statistics();

};


#endif //FIGHTCLUB_SCHEUER_GAME_H
