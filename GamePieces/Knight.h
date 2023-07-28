#pragma once
#include "../GamePieces.h"

class Knight : public GamePieces {

private:





public:

    Knight();

    Knight(sf::String, int, int);

    ~Knight();

    void render(sf::RenderWindow*);

};