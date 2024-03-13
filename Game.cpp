//
// Created by Petra Scheuer on 11.03.24.
//
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

void Game::setGametype(int gametype){
    gametype_=gametype;
}
void Game::startGame() {
    std::string spielerName;
    std::string spielerTyp;

    int spielTyp = 0;

    while (true) {
        std::cout << "Wähle Spieltyp (1 für 1vs1, 2 für 2vs2): ";
        if (std::cin >> spielTyp && (spielTyp == 1 || spielTyp == 2)) {
            setGametype(spielTyp);
            break; // Gültige Eingabe, verlasse die Schleife
        } else {
            std::cout << "Ungültige Ausgabe. Bitte wähle 1 oder 2." << std::endl;
            std::cin.clear(); // Bereinigt den Fehlerzustand von cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoriert den Rest der Eingabe bis zum nächsten Zeilenende
        }
    }

    // Spielerinformationen erfragen
    std::cout << "Gib deinen Namen ein: ";
    std::getline(std::cin, spielerName);
    while (spielerName.empty()) {
        std::cout << "Der Name darf nicht leer sein.";
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

    Enemy gegner;
    gegner.assignSpielfigur();
    gegner.showSpielfigur();
    std::cout << std::endl;

    if (gametype_ == 2){
        Enemy gegner2;
        gegner2.assignSpielfigur();
        gegner2.showSpielfigur();
        std::cout << std::endl;

        Enemy teammate;
        teammate.assignSpielfigur();
        teammate.showSpielfigur();
        std::cout << std::endl;

        std::string input;
        while(67){
            //Zuerst die Abbruchbedingungen
            if(input == "X" || input == "x"){
                break;
            }
            if(spieler.getLifepoints()==0 && teammate.getLifepoints() == 0 || gegner.getLifepoints()==0 && gegner2.getLifepoints()==0){
                if((spieler.getLifepoints()<=0 && teammate.getLifepoints() <= 0)){
                    wincountenemyTeam_++;
                    losecountmyTeam_++;
                    break;
                }
                else if (gegner.getLifepoints()>=0 && gegner2.getLifepoints()>=0){
                    wincountmyTeam_++;
                    losecountenemyTeam_++;
                    break;
                }
            }
            // Ausgabe der Werte zu Beginn des Durchlaufs
            std::cout << "Spieler: " << spieler.getName() << " - Health: " << spieler.getLifepoints() << ", Strength: " << spieler.getStrength() << std::endl;
            std::cout << "Dein Teammate: " << teammate.getName() << " - Health: " << teammate.getLifepoints() << ", Strength: " << teammate.getStrength() << std::endl;
            std::cout << "Gegner: " << gegner.getName() << " - Health: " << gegner.getLifepoints() << ", Strength: " << gegner.getStrength() << std::endl;
            std::cout << "Gegner 2: " << gegner2.getName() << " - Health: " << gegner2.getLifepoints() << ", Strength: " << gegner2.getStrength() << std::endl;

            if( gegner.getLifepoints() >0){
                if(spieler.getLifepoints()>0){
                    gegner.attack(spieler);
                    std::cout<<std::endl;
                }
                else{
                    gegner.attack(teammate);
                    std::cout<<std::endl;
                }
            }
            else {
                std::cout <<gegner.getName()<<" already dead!"<<std::endl;
            }
            if( gegner2.getLifepoints() >0) {
                if (teammate.getLifepoints() > 0) {
                    gegner.attack(teammate);
                    std::cout << std::endl;
                } else {
                    gegner.attack(spieler);
                    std::cout << std::endl;
                }
            }
            else {
                std::cout <<gegner2.getName()<<" already dead!"<<std::endl;
            }
            if( teammate.getLifepoints() >0) {
                if (gegner2.getLifepoints() > 0) {
                    teammate.attack(gegner2);
                    std::cout << std::endl;
                } else {
                    teammate.attack(gegner);
                    std::cout << std::endl;
                }
            }
            else {
                std::cout<<teammate.getName()<<" already dead!"<<std::endl;
                }

            if( spieler.getLifepoints() >0){
                if (gegner.getLifepoints() > 0) {
                    spieler.attack(gegner);
                    std::cout << std::endl;
                } else {
                    spieler.attack(gegner2);
                    std::cout << std::endl;
                }
            }
            else {
                std::cout <<spieler.getName()<<" already dead!"<<std::endl;
            }
        }
    }
    else{

    std::string input;
        while(67){
            if(input == "X" || input == "x"){
                break;
            }
            if(spieler.getLifepoints()<=0 || gegner.getLifepoints()<=0){
                if(spieler.getLifepoints()<=0){
                    losecountmyTeam_++;
                    wincountenemyTeam_++;
                }
                else if(gegner.getLifepoints()<=0){
                    losecountenemyTeam_++;
                    wincountmyTeam_++;
                }
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
}

void Game::Statistics() {
    std::cout << "ENDGAME" << std::endl;
        std::cout << "Dein Team: Gewonnene Spiele: " << wincountmyTeam_ <<" Verlorene Spiele: "<<losecountmyTeam_<< std::endl;
    std::cout << "Gegner Team: Gewonnene Spiele: " << wincountenemyTeam_ <<" Verlorene Spiele: "<<losecountenemyTeam_<< std::endl;

}

