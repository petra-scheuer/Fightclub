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

        std::cout << "Wähle deinen Typ (Feuer, Wasser, Erde, Luft): ";
        std::getline(std::cin, spielerTyp);

        // Spieler initialisieren
        Player spieler(spielerName, spielerTyp);

        // Spielbeginn
        std::cout << "Das Spiel beginnt!" << std::endl;
        std::cout << spieler.getName() << std::endl;

        // Hier würde die Spiellogik folgen...
    }
