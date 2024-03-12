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

    setLifepoints(100);
    setStrength(10);

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
    int count;
    std::cout << "Dein Gegner ist " << getName()<<". Er trainiert ein "<<getTyp()<<" Team. Hier sind seine Spielfiguren: "<<std::endl;

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
void Enemy::chooseAction(Player& spieler) {
    if (spielfiguren.empty()) {
        std::cout << "Keine Spielfiguren vorhanden, Aktion nicht möglich." << std::endl;
        return; // Beende die Methode frühzeitig, wenn keine Spielfiguren vorhanden sind
    }
    if (this->getLifepoints() < 30) { // Wenn Lebenspunkte unter 30%, versuche zu heilen
        std::cout<<"Healing"<<std::endl;
        this->useHealingItem();
    } else {
        std::cout<<"Attack"<<std::endl;
        this->attackPlayer(spieler);
    }
}

void Enemy::useHealingItem() {
    for (auto& figur : spielfiguren) {
        if (figur.getHealing() > 0) {
            // Heile den Gegner mit den Heilungspunkten des Items
            int currentLife = this->getLifepoints();
            this->setLifepoints(currentLife + figur.getHealing());
            std::cout << "Gegner heilt sich mit " << figur.getName() << " um " << figur.getHealing() << " Punkte." << std::endl;
            break; // Breche die Schleife ab, nachdem das erste Heilungs-Item gefunden wurde
        }
    }
}

void Enemy::attackPlayer(Player& spieler) {
    if (spielfiguren.empty()) {
        std::cout << "Keine Spielfiguren vorhanden, Angriff nicht möglich." << std::endl;
        return;
    }

    // Zufällige Spielfigur auswählen
    int index = rand() % spielfiguren.size();
    Spielfigur& ausgewaehlteFigur = spielfiguren[index];

    // Schadenswert ermitteln
    int damage = ausgewaehlteFigur.getDamage();

    // Lebenspunkte des Spielers reduzieren
    int spielerLife = spieler.getLifepoints() - damage;
    spieler.setLifepoints(spielerLife);

    // Ausgabe des Angriffs
    std::cout << "Gegner greift an mit " << ausgewaehlteFigur.getName()
              << " und verursacht " << damage << " Schaden." << std::endl;
}
