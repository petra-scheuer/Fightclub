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

    // Zufälligen Namen auswählen
    std::string namen[] = {
            "Lance", "Cynthia", "Alder", "Iris", "Diantha",
            "Steven", "Wallace", "Leon", "Red", "Blue",
            "Trace", "Mustard", "Peony", "N", "Ghetsis",
            "Lysandre", "Guzma", "Elesa", "Skyla", "Hilda"
    };

    int nameIndex = rand() % 20; // Erzeugt eine Zufallszahl zwischen 0 und 19
    setName(namen[nameIndex]);
    nameIndex++;
    if(nameIndex >16){
        nameIndex =0;
    }


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

void Enemy::attack(ICombatant& target) {
    if (spielfiguren.empty()) {
        std::cerr << "Keine Spielfiguren verfügbar." << std::endl;
        return;
    }

    // Verwendung des aktuellen Index, um die Spielfigur auszuwählen
    Spielfigur& ausgewaehlteFigur = spielfiguren[currentIndex];


    std::cout << getName()<<" greift mit " << ausgewaehlteFigur.getName()
              << " an, die " << ausgewaehlteFigur.getDamage() << " Schaden verursacht." << std::endl;

    target.takeDamage(ausgewaehlteFigur.getDamage());
    int currentHealth = getLifepoints();
    setLifepoints(currentHealth + ausgewaehlteFigur.getHealing()); // Heile den Enemy basierend auf der Heilung der Spielfigur

    std::cout << "Enemy heilt sich selbst um " << ausgewaehlteFigur.getHealing() << " Punkte." << std::endl;

    // Inkrementieren des aktuellen Index für den nächsten Angriff
    currentIndex = (currentIndex + 1) % spielfiguren.size();
}


void Enemy::takeDamage(int amount)  {
    int lifepoints= getLifepoints()-amount;

    setLifepoints(lifepoints);


    std::cout << getName()<<" nimmt " << amount << " Schaden. Verbleibende Lebenspunkte: " << lifepoints << std::endl;
}

