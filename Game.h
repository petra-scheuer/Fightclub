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
    Enemy teammate;
    Enemy gegner;
    Enemy gegner2;
    unsigned int wincountmyTeam_;
    unsigned int wincountenemyTeam_;
    unsigned int losecountmyTeam_;
    unsigned int losecountenemyTeam_;

    int gametype_;
public:
    Game() : wincountmyTeam_(0), wincountenemyTeam_(0), losecountmyTeam_(0), losecountenemyTeam_(0), gametype_(0) {}
    void startGame();
    void Statistics();
    void setGametype(int gametype);


};


#endif //FIGHTCLUB_SCHEUER_GAME_H
