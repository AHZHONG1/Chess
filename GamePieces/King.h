#pragma once
#include "../GamePieces.h"

class King : public GamePieces {

private:





public:

    King();

    King(sf::String, int, int);

    ~King();

    void render(sf::RenderWindow*);

};