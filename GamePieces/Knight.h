#pragma once
#include "../GamePieces.h"
#include "../General.h"

class Knight : public GamePieces {

private:





public:

    Knight();

    Knight(sf::String, int, int, Player);

    ~Knight();

    void render(sf::RenderWindow*);

};