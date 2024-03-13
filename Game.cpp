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
    while (spielerName.empty()) {
        std::cout << "Der Name darf nicht leer sein. Gib bitte deinen Namen ein: ";
        std::getline(std::cin, spielerName);
    }
    spieler.setName(spielerName); // Direkte Verwendung der Klassenvariable 'spieler'

    std::cout << "Wähle deinen Typ (Feuer, Wasser, Erde, Luft): ";
    std::getline(std::cin, spielerTyp);
    while (spielerTyp != "Feuer" && spielerTyp != "Wasser" && spielerTyp != "Erde" && spielerTyp != "Luft") {
        std::cout << "Ungültiger Typ. Bitte wähle zwischen Feuer, Wasser, Erde und Luft: ";
        std::getline(std::cin, spielerTyp);
    }
    spieler.setTyp(spielerTyp);

    spieler.setLifepoints(100); // Setze Health
    spieler.setStrength(10); // Setze Strength

    std::cout << "Hallo " << spieler.getName() << "! Du bist nun Trainer eines " << spieler.getTyp() << " Teams." << std::endl;
    spieler.chooseSpielfigur();

    // Gegner
    Enemy gegner;
    gegner.assignSpielfigur();
    gegner.showSpielfigur();
    std::cout << std::endl;

    std::string input;
        while(67){
            if(input == "X" || input == "x"){
                break;
            }
            if(spieler.getLifepoints()<=0 || gegner.getLifepoints()<=0){
                break;
            }
            // Ausgabe der Werte zu Beginn des Durchlaufs
            std::cout << "Spieler: " << spieler.getName() << " - Health: " << spieler.getLifepoints() << ", Strength: " << spieler.getStrength() << std::endl;
            std::cout << "Gegner: " << gegner.getName() << " - Health: " << gegner.getLifepoints() << ", Strength: " << gegner.getStrength() << std::endl;
            std::cout<<std::endl;
            gegner.attack(spieler);
            spieler.attack(gegner);
        }
}

void Game::Statistics(){
    std::cout<<"ENDGAME"<<std::endl;
    std::cout<<"Wincount Spieler: "<<spieler.getWincount()<<std::endl; std::cout<<"Losecount Spieler: "<<spieler.getLosecount()<<std::endl;
    std::cout<<"Wincount Gegner: "<<gegner.getWincount()<<std::endl; std::cout<<"Losecount Gegner: "<<gegner.getLosecount()<<std::endl;
}
