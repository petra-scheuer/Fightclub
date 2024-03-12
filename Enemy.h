//
// Created by Petra Scheuer on 11.03.24.
//

#ifndef FIGHTCLUB_SCHEUER_ENEMY_H
#define FIGHTCLUB_SCHEUER_ENEMY_H
#include <iostream>
#include <string>
#include <cstdlib> //Für rand()
#include <ctime> // Für time()
#include "Charakter.h"
#include "Spielfiguren.h"


class Enemy : public Charakter {
private:
    std::string typ_;
    std::vector<Spielfigur> spielfiguren; // Hinzufügen der Liste von Pokémon
public:
    Enemy(); //Konstruktor

    //setter und getter
    void setTyp(std::string typ);
    std::string getTyp();
    void assignSpielfigur();
    void showSpielfigur();

};


#endif //FIGHTCLUB_SCHEUER_ENEMY_H
