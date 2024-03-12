//
// Created by Petra Scheuer on 12.03.24.
//

#include "Spielfiguren.h"
void Spielfigur::setName(const std::string& name) {
    this->name_ = name;
}

void Spielfigur::setItem(const std::string& item) {
    this->item_ = item;
}

void Spielfigur::setTyp(std::string typ) {
    this->typ_ = typ;
}

std::string Spielfigur::getName() const {
    return name_;
}

std::string Spielfigur::getItem() const {
    return item_;
}

std::string Spielfigur::getTyp() const {
    return typ_;
}
int Spielfigur::getDamage() const {
    return damage_;
}

int Spielfigur::getHealing() const {
    return healing_;
}


std::vector<Spielfigur> Spielfigur::erstelleVerfuegbareSpielfiguren() {
    return {
            // Wasser
            Spielfigur("Squirtle", "Wasserball", "Wasser",15,5 ),
            Spielfigur("Psyduck", "Kopfschmerz", "Wasser", 10,5),
            Spielfigur("Poliwag", "Hypnose", "Wasser",5,20),
            Spielfigur("Vaporeon", "Hydropumpe", "Wasser",20,5),
            // Feuer
            Spielfigur("Charmander", "Flammenwurf", "Feuer",20,5),
            Spielfigur("Vulpix", "Feuerfeger", "Feuer",15,10),
            Spielfigur("Growlithe", "Glut", "Feuer",5,20),
            Spielfigur("Ponyta", "Feuersturm", "Feuer",10,10),
            // Luft
            Spielfigur("Pidgey", "Wirbelwind", "Luft",5,15),
            Spielfigur("Spearow", "Luftschnitt", "Luft",15,5),
            Spielfigur("Zubat", "Superschall", "Luft",20,-5),
            Spielfigur("Aerodactyl", "Himmelsfeger", "Luft",10,5),
            // Erd-Pokémon
            Spielfigur("Geodude", "Steinwurf", "Erde",10,5),
            Spielfigur("Onix", "Erdbeben", "Erde",20,-5),
            Spielfigur("Rhyhorn", "Schlammlawine", "Erde",20,-5),
            Spielfigur("Sandshrew", "Sandgrab", "Erde",10,20)
    };
}
