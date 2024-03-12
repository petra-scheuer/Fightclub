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
            Spielfigur("Squirtle", "Wasserball", "Wasser"),
            Spielfigur("Psyduck", "Kopfschmerz", "Wasser"),
            Spielfigur("Poliwag", "Hypnose", "Wasser"),
            Spielfigur("Vaporeon", "Hydropumpe", "Wasser"),
            // Feuer
            Spielfigur("Charmander", "Flammenwurf", "Feuer"),
            Spielfigur("Vulpix", "Feuerfeger", "Feuer"),
            Spielfigur("Growlithe", "Glut", "Feuer"),
            Spielfigur("Ponyta", "Feuersturm", "Feuer"),
            // Luft
            Spielfigur("Pidgey", "Wirbelwind", "Luft"),
            Spielfigur("Spearow", "Luftschnitt", "Luft"),
            Spielfigur("Zubat", "Superschall", "Luft"),
            Spielfigur("Aerodactyl", "Himmelsfeger", "Luft"),
            // Erd-Pokémon
            Spielfigur("Geodude", "Steinwurf", "Erde"),
            Spielfigur("Onix", "Erdbeben", "Erde"),
            Spielfigur("Rhyhorn", "Schlammlawine", "Erde"),
            Spielfigur("Sandshrew", "Sandgrab", "Erde")
    };
}