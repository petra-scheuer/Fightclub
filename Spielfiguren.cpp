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

std::vector<Spielfigur> Spielfigur::erstelleVerfuegbareSpielfiguren() {
    return {
            // Wasser
            Spielfigur("Squirtle", "Wasserball", "Wasser",15,0 ),
            Spielfigur("Psyduck", "Kopfschmerz", "Wasser", 10,5),
            Spielfigur("Poliwag", "Hypnose", "Wasser",0,20),
            Spielfigur("Vaporeon", "Hydropumpe", "Wasser",20,0),
            // Feuer
            Spielfigur("Charmander", "Flammenwurf", "Feuer",20,0),
            Spielfigur("Vulpix", "Feuerfeger", "Feuer",15,0),
            Spielfigur("Growlithe", "Glut", "Feuer",0,20),
            Spielfigur("Ponyta", "Feuersturm", "Feuer",10,10),
            // Luft
            Spielfigur("Pidgey", "Wirbelwind", "Luft",0,10),
            Spielfigur("Spearow", "Luftschnitt", "Luft",15,0),
            Spielfigur("Zubat", "Superschall", "Luft",20,0),
            Spielfigur("Aerodactyl", "Himmelsfeger", "Luft",10,5),
            // Erd-Pokémon
            Spielfigur("Geodude", "Steinwurf", "Erde",10,0),
            Spielfigur("Onix", "Erdbeben", "Erde",20,-5),
            Spielfigur("Rhyhorn", "Schlammlawine", "Erde",10,0),
            Spielfigur("Sandshrew", "Sandgrab", "Erde",0,20)
    };
}