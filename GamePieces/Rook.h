#pragma once
#include "../GamePieces.h"
#include "../General.h"

class Rook : public GamePieces {

private:





public:

    Rook();

    Rook(sf::String, int, int, Player);

    ~Rook();

    void render(sf::RenderWindow*);

};