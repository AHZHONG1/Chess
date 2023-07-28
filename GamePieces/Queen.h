#pragma once
#include "../GamePieces.h"

class Queen : public GamePieces {

private:





public:

    Queen();

    Queen(sf::String, int, int);

    ~Queen();

    void render(sf::RenderWindow*);

};