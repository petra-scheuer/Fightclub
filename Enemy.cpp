//
// Created by Petra Scheuer on 11.03.24.
//
#include "Enemy.h"


void Enemy::setTyp(std::string typ){
    typ_=typ;
}
std::string Enemy::getTyp(){
    return typ_;
}
Enemy::Enemy() {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialisiert den Zufallszahlengenerator

    // Zufälligen Namen auswählen
    std::string namen[] = {"Blue", "Champion Oak"};
    int nameIndex = rand() % 2; // Erzeugt eine Zufallszahl 0 oder 1
    setName(namen[nameIndex]);

    // Zufälligen Typ auswählen
    std::string typen[] = {"Feuer", "Wasser", "Luft", "Erde"};
    int typIndex = rand() % 4; // Erzeugt eine Zufallszahl zwischen 0 und 3
    setTyp(typen[typIndex]);
}
