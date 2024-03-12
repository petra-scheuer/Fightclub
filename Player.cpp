//
// Created by Petra Scheuer on 11.03.24.
//
#include "Player.h"

void Player::setTyp(std::string typ){
    typ_=typ;
}
std::string Player::getTyp(){
    return typ_;
}
void Player::chooseSpielfigur() {
    std::vector<Spielfigur> verfuegbareSpielfiguren = Spielfigur::erstelleVerfuegbareSpielfiguren();
    int count = 0; // Zähler für die Anzeige

    // Anzeige aller Spielfiguren in Gruppen von vier
    for(size_t i = 0; i < verfuegbareSpielfiguren.size(); ++i) {
        const auto& figur = verfuegbareSpielfiguren[i];
        std::cout << i + 1 << ". " << figur.getName() << " (" << figur.getTyp() << ")";
        count++;
        if (count % 4 == 0) { // Nach jeweils vier Einträgen einen Zeilenumbruch einfügen
            std::cout << std::endl;
        } else {
            std::cout << "\t"; // Füge einen Tabulator für die Trennung innerhalb der Zeile hinzu
        }
    }
    if (count % 4 != 0) { // Füge einen abschließenden Zeilenumbruch hinzu, falls die letzte Zeile nicht vollständig ist
        std::cout << std::endl;
    }

    // Nachfolgend bleibt der Teil für die Auswahl und die Ausgabe der ausgewählten Spielfiguren unverändert
    std::cout << "Wähle deine Spielfiguren aus (durch Komma getrennt): ";
    std::string eingabe;
    std::getline(std::cin, eingabe);
    std::stringstream eingabeStream(eingabe);
    std::string zahl;

    while(std::getline(eingabeStream, zahl, ',')) {
        try {
            int index = std::stoi(zahl) - 1; // Umwandlung in Index
            if(index >= 0 && index < verfuegbareSpielfiguren.size()) {
                this->spielfiguren.push_back(verfuegbareSpielfiguren[index]);
            } else {
                std::cout << "Ungültige Auswahl: " << zahl << std::endl;
            }
        } catch(const std::exception& e) {
            std::cout << "Ungültige Eingabe: " << zahl << std::endl;
        }
    }
    std::cout<<std::endl;

    // Zeige die Auswahl des Spielers
    std::cout << std::endl<<"Deine ausgewählten Spielfiguren: " << std::endl;

    for(const auto& figur : this->spielfiguren) {
        std::cout << "- " << figur.getName() << " (" << figur.getTyp() << ")";
        if (++count % 4 == 0) { // Nach jeweils drei Spielfiguren einen Zeilenumbruch hinzufügen
            std::cout << std::endl;
        } else {
            std::cout << "\t"; // Füge einen Tabulator für die Trennung innerhalb der Zeile hinzu
        }
    }
    if (count % 3 != 0) { // Füge einen abschließenden Zeilenumbruch hinzu, falls die letzte Zeile nicht vollständig ist
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}
Player::Player() {
    // Initialwerte setzen
    setName("Unbekannter Spieler");
    setTyp("Unbekannt");
    setLifepoints(100); // Beispielwert
    setStrength(10); // Beispielwert
}

    std::string Player::showSpielfiguren() const {
        std::string spielfigurenListe;
        for (const auto& figur : spielfiguren) {
            if (!spielfigurenListe.empty()) {
                spielfigurenListe += ", "; // Trennzeichen hinzufügen, wenn nicht der erste Eintrag
            }
            spielfigurenListe += figur.getName(); // Name der Spielfigur hinzufügen
        }
        return spielfigurenListe;
    }

void Player::showDetail() const {
    for (const auto& figur : spielfiguren) {
        // Direkte Ausgabe jeder Spielfigur mit ihren Details
        std::cout << figur.getName()
                  << " - Attacke: " << figur.getItem()
                  << ", Damage: " << std::to_string(figur.getDamage())
                  << ", Health: " << std::to_string(figur.getHealing())
                  << std::endl;
    }
}

