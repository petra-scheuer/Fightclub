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
void Enemy::assignSpielfigur() {
    // Hole alle verfügbaren Spielfiguren
    std::vector<Spielfigur> verfuegbareSpielfiguren = Spielfigur::erstelleVerfuegbareSpielfiguren();
    int anzahlSpielfiguren = verfuegbareSpielfiguren.size();

    // Initialisiere den Zufallszahlengenerator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Wähle drei einzigartige Spielfiguren aus
    for(int i = 0; i < 3; ++i) {
        int index = rand() % anzahlSpielfiguren;
        spielfiguren.push_back(verfuegbareSpielfiguren[index]);

    }
}
void Enemy::showSpielfigur() {
    std::cout << " Spielfiguren von " << getName()<<std::endl;

    for(const auto& spielfigur : spielfiguren) {
        std::cout << "- " << spielfigur.getName() << std::endl;
    }
}
