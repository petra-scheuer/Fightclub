//
// Created by Petra Scheuer on 11.03.24.
//
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

    void Game::startGame() {
        std::string spielerName;
        std::string spielerTyp;

        // Spielerinformationen erfragen
        std::cout << "Gib deinen Namen ein: ";
        std::getline(std::cin, spielerName);
        spieler.setName(spielerName); // Setze den Namen des Spieler-Objekts

        std::cout << "Wähle deinen Typ (Feuer, Wasser, Erde, Luft): ";
        std::getline(std::cin, spielerTyp);
        spieler.setTyp(spielerTyp); // Setze den Typ des Spieler-Objekts

        spieler.setLifepoints(100); // Setze Health
        spieler.setStrength(10); // Setze Strength

        // Spieler initialisieren
        Player spieler(spielerName, spielerTyp);
        std::cout << "Hallo "<<spieler.getName()<<"!. Du bist nun Trainer eines "<<spieler.getTyp()<< " Teams."<<std::endl;
        spieler.chooseSpielfigur();
        //Gegner
        Enemy gegner;
        gegner.assignSpielfigur();
        gegner.showSpielfigur();

        // Hier würde die Spiellogik folgen...
    }
    void Game::gameLoop(){
    std::string input;
        while(67){
            if(input == "X" || input == "x"){
                break;
            }
            // Ausgabe der Werte zu Beginn des Durchlaufs
            std::cout << "Spieler: " << spieler.getName() << " - Health: " << spieler.getLifepoints() << ", Strength: " << spieler.getStrength() << std::endl;
            std::cout << "Gegner: " << gegner.getName() << " - Health: " << gegner.getLifepoints() << ", Strength: " << gegner.getStrength() << std::endl;
            std::cin >> input;
        }
};

void Game::Statistics(){
    std::cout<<"ENDGAME"<<std::endl;
}
