#pragma once
#include "../GamePieces.h"
#include "../General.h"

class Pawn : public GamePieces {

private:





public:

    Pawn();

    Pawn(sf::String, int, int, Player);

    ~Pawn();

    void render(sf::RenderWindow*);

};