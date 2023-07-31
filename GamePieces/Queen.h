#pragma once
#include "../GamePieces.h"
#include "../General.h"

class Queen : public GamePieces {

private:





public:

    Queen();

    Queen(sf::String, int, int, Player);

    ~Queen();

    void render(sf::RenderWindow*);

};