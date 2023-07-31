#pragma once
#include "../GamePieces.h"
#include "../General.h"

class Bishop : public GamePieces {

private:





public:

    Bishop();

    Bishop(sf::String, int, int, Player);

    ~Bishop();

    void render(sf::RenderWindow*);

};