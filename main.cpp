
#include "Header.h"
#include "Game.h"


int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Game myGame;
    myGame.startGame();
    myGame.Statistics();
    return 0;
}
