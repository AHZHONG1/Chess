#pragma once
#include "../GamePieces.h"

class Pawn : public GamePieces {

private:





public:

    Pawn();

    Pawn(sf::String, int, int);

    ~Pawn();

    void render(sf::RenderWindow*);

};