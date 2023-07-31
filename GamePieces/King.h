#pragma once
#include "../GamePieces.h"
#include "../General.h"

class King : public GamePieces {

private:





public:

    King();

    King(sf::String, int, int, Player);

    ~King();

    void render(sf::RenderWindow*);

};