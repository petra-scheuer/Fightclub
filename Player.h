//
// Created by Petra Scheuer on 11.03.24.
#ifndef FIGHTCLUB_SCHEUER_PLAYER_H
#define FIGHTCLUB_SCHEUER_PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Charakter.h"
#include "Spielfiguren.h"


class Player: public Charakter {
private:
    std::string typ_;
    std::vector<Spielfigur> spielfiguren;
public:
    //setter und getter
    std::string getTyp();
    void setTyp(std::string typ);
    Player(const std::string& name, const std::string& typ) {
        setName(name);
        setTyp(typ);
        setLifepoints(100); // Beispielwert
        setStrength(100); // Beispielwert
    }
};
#endif //FIGHTCLUB_SCHEUER_PLAYER_H
