//
// Created by Petra Scheuer on 11.03.24.
//
#ifndef FIGHTCLUB_SCHEUER_CHARAKTER_H
#define FIGHTCLUB_SCHEUER_CHARAKTER_H
#include "Header.h"

class Charakter {
private:
    std::string Name_;
    int lifepoints_;
    int strength_;
    int wincount_;
    int losecount_;
public:
    //Setter und getter
    void setName(std::string Name);
    void setLifepoints(int lifepoints);
    void setStrength(int strength);
    std::string getName();
    int getLifepoints();
    int getStrength();
    int getWincount();
    int getLosecount();
};


#endif //FIGHTCLUB_SCHEUER_CHARAKTER_H
