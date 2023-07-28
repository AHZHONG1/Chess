#pragma once
#include "../GamePieces.h"

class Bishop : public GamePieces {

private:





public:

    Bishop();

    Bishop(sf::String, int, int);

    ~Bishop();

    void render(sf::RenderWindow*);

};